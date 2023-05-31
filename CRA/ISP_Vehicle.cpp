// IPS(Interface Segregation Principle)
#pragma once
#include "ISP_Switches.cpp"

class Vehicle : public Engine {
public:
	bool IsEngineRunning() {
		return engine_running_;
	}

	void StartEngine() override {
		engine_running_ = true;
	}

	void ShutDownEngine() override {
		engine_running_ = false;
	}

private:
	bool engine_running_;
};