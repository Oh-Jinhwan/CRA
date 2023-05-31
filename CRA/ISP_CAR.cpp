// IPS(Interface Segregation Principle)
#pragma once
#include "ISP_Vehicle.cpp"

class Car : public Vehicle, public Radio {
public:
	bool IsRadioOn() {
		return radio_on_;
	}

	void TurnRadioOn() override {
		radio_on_ = true;
	}

	void TurnRadioOff() override {
		radio_on_ = false;
	}

	//void TurnCameraOn() override {
	//	// nothing to do here
	//}

	//void TurnCameraOff() override {
	//	// nothing to do here
	//}

private:
	bool radio_on_;
};