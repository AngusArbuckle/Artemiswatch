#ifndef CLOCKSTAR_FIRMWARE_SETTINGS_H
#define CLOCKSTAR_FIRMWARE_SETTINGS_H

#include <nvs.h>

enum Theme {
	Default [[maybe_unused]],
	Theme1 [[maybe_unused]],
	Theme2 [[maybe_unused]],
	Theme3 [[maybe_unused]],
	Theme4 [[maybe_unused]],
	Theme5 [[maybe_unused]],
	Theme6 [[maybe_unused]],
	Theme7 [[maybe_unused]],
	Theme8 [[maybe_unused]],
	Theme9 [[maybe_unused]]
};

struct SettingsStruct {
	bool notificationSounds = true;
	uint8_t screenBrightness = 100;
	uint8_t sleepTime = 1;
	bool ledEnable = true;
	bool motionDetection = true;
	Theme theme = Default;
};

class Settings {
public:
	Settings();

	SettingsStruct get();
	void set(SettingsStruct& settings);
	void store();

	static constexpr uint8_t SleepSteps = 5;
	static constexpr const uint32_t SleepSeconds[SleepSteps] = { 0, 30, 60, 2 * 60, 5 * 60 };
	static constexpr const char* SleepText[SleepSteps] = { "OFF", "30 sec", "1 min", "2 min", "5 min" };

private:
	nvs_handle_t handle{};
	SettingsStruct settingsStruct;

	static constexpr const char* NVSNamespace = "Clockstar";
	static constexpr const char* BlobName = "Settings";

	void load();
};


#endif //CLOCKSTAR_FIRMWARE_SETTINGS_H
