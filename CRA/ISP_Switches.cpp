// IPS(Interface Segregation Principle)
#pragma once
#define interface struct

interface Engine {
	virtual void StartEngine() = 0;
	virtual void ShutDownEngine() = 0;
};

interface Radio{
	virtual void TurnRadioOn() = 0;
	virtual void TurnRadioOff() = 0;
};

interface Camera{
	virtual void TurnCameraOn() = 0;
	virtual void TurnCameraOff() = 0;
};