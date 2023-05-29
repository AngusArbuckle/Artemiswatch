#include <esp_log.h>
#include "Char.h"

static const char* TAG = "BLE::Char";

Char::Char(esp_bt_uuid_t uuid, esp_gatt_char_prop_t props) : uuid(uuid), props(props), notifQueue((props & ESP_GATT_CHAR_PROP_BIT_NOTIFY) ? 12 : 1){

}

std::unique_ptr<Char::Notif> Char::getNextNotif(TickType_t wait){
	if(!(props & ESP_GATT_CHAR_PROP_BIT_NOTIFY) || !(remoteProps & ESP_GATT_CHAR_PROP_BIT_NOTIFY)){
		ESP_LOGW(TAG, "Requesting notify, but NOTIFY property bit isn't");
		return nullptr;
	}

	return notifQueue.get(wait);
}

void Char::setOnConnectedCb(ConnectedCB cb){
	onConnectedCB = cb;
}

bool Char::established(){
	return chr != nullptr;
}

bool Char::connected(){
	return configsDone.size() == (int) Config::COUNT;
}

void Char::establish(std::unique_ptr<CharInfo> info, esp_gatt_char_prop_t rProps){
	ESP_LOGI(TAG, "Established");
	chr = std::move(info);

	remoteProps = rProps;

	if(props & ESP_GATT_CHAR_PROP_BIT_NOTIFY){
		if(remoteProps & ESP_GATT_CHAR_PROP_BIT_NOTIFY){
			chr->regForNotify();
		}else{
			ESP_LOGW(TAG, "Have NOTIFY bit set, but remote characteristic doesn't");
		}
	}else{
		configDone(Config::Notify);
	}

	if(props & ESP_GATT_CHAR_PROP_BIT_WRITE){
		if(!(remoteProps & ESP_GATT_CHAR_PROP_BIT_WRITE)){
			ESP_LOGW(TAG, "Have WRITE bit set, but remote characteristic doesn't");
		}
	}
}

void Char::close(){
	if(!chr) return;
	ESP_LOGI(TAG, "Closed");

	chr.reset();
	remoteProps = 0;
	configsDone.clear();
}

void Char::configDone(Char::Config config){
	configsDone.insert(config);
	if(configsDone.size() == (int) Config::COUNT){
		if(onConnectedCB){
			onConnectedCB();
		}
	}
}

void Char::onRegNotify(const esp_ble_gattc_cb_param_t::gattc_reg_for_notify_evt_param* param){
	if(param->status != ESP_GATT_OK){
		ESP_LOGE(TAG, "reg for notify failed, error status = 0x%x", param->status);
		return;
	}

	ESP_LOGI(TAG, "Registered for notify");
	configDone(Config::Notify);
}

void Char::onNotify(const esp_ble_gattc_cb_param_t::gattc_notify_evt_param* param){
	if(notifQueue.size != 1){
		notifQueue.post(std::make_unique<Notif>(std::vector(param->value, param->value + param->value_len), !param->is_notify), 0);
	}
}

void Char::onWriteResp(esp_gattc_cb_event_t evt, const esp_ble_gattc_cb_param_t::gattc_write_evt_param* param){
	if(param->status != ESP_GATT_OK){
		ESP_LOGE(TAG, "write failed, error status = 0x%x", param->status);
		return;
	}
}

void Char::writeDescr(uint16_t uuid, const std::vector<uint8_t>& data){
	if(!connected()) return;

	esp_bt_uuid_t id = { .len = 2, .uuid = { .uuid16 = uuid } };
	chr->writeDescr(id, (uint8_t*) data.data(), data.size());
}

void Char::write(const std::vector<uint8_t>& data){
	if(!connected()) return;

	if(!(props & ESP_GATT_CHAR_PROP_BIT_WRITE) || !(remoteProps & ESP_GATT_CHAR_PROP_BIT_WRITE)){
		ESP_LOGW(TAG, "Requesting writy, but WRITE property bit isn't");
		return;
	}

	chr->write((uint8_t*) data.data(), data.size(), true);
}
