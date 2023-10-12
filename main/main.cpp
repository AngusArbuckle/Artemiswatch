#include <driver/gpio.h>
#include <nvs_flash.h>
#include "Settings/Settings.h"
#include "Pins.hpp"
#include "Periph/I2C.h"
#include "Periph/PinOut.h"
#include "Periph/Bluetooth.h"
#include "Devices/Battery.h"
#include "Devices/Display.h"
#include "Devices/Input.h"
#include "Devices/IMU.h"
#include "BLE/GAP.h"
#include "BLE/Client.h"
#include "BLE/Server.h"
#include "Notifs/Phone.h"
#include "LV_Interface/LVGL.h"
#include "LV_Interface/FSLVGL.h"
#include "LV_Interface/InputLVGL.h"
#include <lvgl/lvgl.h>
#include "Theme/theme.h"
#include "Util/Services.h"
#include "Services/BacklightBrightness.h"
#include "Services/ChirpSystem.h"
#include "Services/Time.h"
#include "Services/StatusCenter.h"
#include "Services/SleepMan.h"
#include "Screens/ShutdownScreen.h"
#include "Screens/Lock/LockScreen.h"
#include "JigHWTest/JigHWTest.h"
#include "Util/Notes.h"
#include "Util/stdafx.h"
#include "esp_heap_caps.h"
#include "Periph/WiFiSTA.h"
#include "Services/TCPClient.h"

LVGL* lvgl;
BacklightBrightness* bl;
SleepMan* sleepMan;

void startHeapMonitor(){
	static const uint32_t MeasureInt = 50;
	static const uint32_t ReportInt = 1000;
	static uint32_t minHeap = 0, maxBlock = 0;

	auto heapThread = new ThreadedClosure([](){
		uint32_t heap = 0;
		uint32_t block = 0;
		for(int i = 0; i < ReportInt / MeasureInt; ++i){
			heap = heap_caps_get_free_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
			block = heap_caps_get_largest_free_block(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);

			if(heap < minHeap || minHeap == 0){
				minHeap = heap;
			}
			if(block < maxBlock || maxBlock == 0){
				maxBlock = block;
			}
			vTaskDelay(MeasureInt);
		}
		printf("current: heap: %lu, largest block: %lu | minimum: heap: %lu, largest block: %lu \n", heap, block, minHeap, maxBlock);
	}, "HeapThread", 3*1024);
	heapThread->start();
}

void shutdown(){
	lvgl->stop(0);
	lvgl->startScreen([](){ return std::make_unique<ShutdownScreen>(); });
	lv_timer_handler();
	sleepMan->wake(true);
	if(!bl->isOn()){
		bl->fadeIn();
	}
	vTaskDelay(SleepMan::ShutdownTime-1000);
	sleepMan->shutdown();
}

static const gpio_num_t PWDN = GPIO_NUM_26;
static const gpio_num_t LEDs[] = { GPIO_NUM_43, GPIO_NUM_44 };

void setLEDs(){
	for(int i = 0; i < sizeof(LEDs)/sizeof(LEDs[0]); i++){
		const gpio_config_t cfg = {
				.pin_bit_mask = 1ULL << LEDs[i],
				.mode = GPIO_MODE_OUTPUT
		};
		gpio_config(&cfg);
		gpio_set_level((gpio_num_t) LEDs[i], 0);
	}
}

void init(){
	setLEDs();
	startHeapMonitor();

	esp_log_level_set("WiFi_STA", ESP_LOG_VERBOSE);
	esp_log_level_set("TCPClient", ESP_LOG_VERBOSE);


	if(JigHWTest::checkJig()){
		printf("Jig\n");
		auto test = new JigHWTest();
		test->start();
		vTaskDelete(nullptr);
	}

	gpio_install_isr_service(ESP_INTR_FLAG_LOWMED | ESP_INTR_FLAG_SHARED | ESP_INTR_FLAG_IRAM);

	auto ret = nvs_flash_init();
	if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND){
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	auto settings = new Settings();
	Services.set(Service::Settings, settings);

	auto blPwm = new PWM(PIN_BL, LEDC_CHANNEL_1, true);
	blPwm->detach();
	bl = new BacklightBrightness(blPwm);
	Services.set(Service::Backlight, bl);

	auto buzzPwm = new PWM(PIN_BUZZ, LEDC_CHANNEL_0);
	auto audio = new ChirpSystem(*buzzPwm);
	Services.set(Service::Audio, audio);

	auto i2c = new I2C(I2C_NUM_0, (gpio_num_t) I2C_SDA, (gpio_num_t) I2C_SCL);
	auto imu = new IMU(*i2c);
	Services.set(Service::IMU, imu);

	auto disp = new Display();
	auto input = new Input();
	Services.set(Service::Input, input);

	lvgl = new LVGL(*disp);
	auto theme = theme_init(lvgl->disp());
	lv_disp_set_theme(lvgl->disp(), theme);

	auto lvglInput = new InputLVGL();
	auto fs = new FSLVGL('S');

	sleepMan = new SleepMan(*lvgl);
	Services.set(Service::Sleep, sleepMan);

	auto status = new StatusCenter();
	Services.set(Service::Status, status);

	auto battery = new Battery(); // Battery is doing shutdown
	if(battery->isShutdown()) return; // Stop initialization if battery is critical
	Services.set(Service::Battery, battery);

	auto rtc = new RTC(*i2c);
	auto time = new Time(*rtc);
	Services.set(Service::Time, time); // Time service is required as soon as Phone is up

	auto bt = new Bluetooth();
	auto gap = new BLE::GAP();
	auto client = new BLE::Client(gap);
	auto server = new BLE::Server(gap);
	auto phone = new Phone(server, client);
	server->start();
	Services.set(Service::Phone, phone);

	FSLVGL::loadCache();

	// Load start screen here
	lvgl->startScreen([](){ return std::make_unique<LockScreen>(); });

	if(settings->get().notificationSounds){
		audio->play({
							Chirp{ .startFreq = NOTE_E4, .endFreq = NOTE_GS4, .duration = 100 },
							Chirp{ .startFreq = 0, .endFreq = 0, .duration = 200 },
							Chirp{ .startFreq = NOTE_GS4, .endFreq = NOTE_B4, .duration = 100 },
							Chirp{ .startFreq = 0, .endFreq = 0, .duration = 200 },
							Chirp{ .startFreq = NOTE_B4, .endFreq = NOTE_E5, .duration = 100 }
					});
	}

	// Start UI thread after initialization
	lvgl->start();

	bl->fadeIn();

	// Start Battery scanning after everything else, otherwise Critical
	// Battery event might come while initialization is still in progress
	battery->begin();

	auto wifi = new WiFiSTA();
	wifi->connect();
	while(wifi->getState() != WiFiSTA::Connected){
		vTaskDelay(100);
	}
	auto tcp = new TCPClient();
	tcp->connect();
	while(!tcp->isConnected()){
		vTaskDelay(100);
	}
	static const char t[] = "Hello";
	tcp->write((uint8_t*)t, 6);
	auto heap = heap_caps_get_free_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
	auto block = heap_caps_get_largest_free_block(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
	printf("tcp connect: heap: %zu largest block: %zu \n", heap, block);
}

extern "C" void app_main(void){
	init();

	vTaskDelete(nullptr);
}
