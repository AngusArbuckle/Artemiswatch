#ifndef CLOCKSTAR_FIRMWARE_BANGLE_H
#define CLOCKSTAR_FIRMWARE_BANGLE_H

#include "Notifs/NotifSource.h"
#include "BLE/Server.h"
#include "BLE/UART.h"

class Bangle : public NotifSource, private Threaded {
public:
	Bangle(BLE::Server* server);
	virtual ~Bangle();

	void actionPos(uint32_t uid) override;
	void actionNeg(uint32_t uid) override;

	void findPhoneStart();
	void findPhoneStop();

private:
	BLE::Server* server;
	BLE::UART uart;

	void loop() override;

	void handleCommand(const std::string& line);

	// command handlers
	void handle_isGpsActive();
	void handle_find(bool on);
	void handle_notify(const std::string& prop);
	void handle_notifyDel(uint32_t id);

	float timeOffset = 0;
	uint64_t timeUnix = 0;

	void setTime();

	bool connected = false;
	void onConnect();
	void onDisconnect();

};


#endif //CLOCKSTAR_FIRMWARE_BANGLE_H
