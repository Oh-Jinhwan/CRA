// Open/Closed Principle
#include "OCP_Vehicle.cpp"

class EventHandler {
public:
	EventHandler(Vehicle *vehicle) {
		vehicle_ = vehicle;
	}

	void changeDrivingMode(DrivingMode *driving_mode) {
		vehicle_->SetPower(driving_mode->GetPower());
		vehicle_->SetSuspensionHeight(driving_mode->GetSuspendHeight());
	}

private:
	Vehicle *vehicle_;
};

int main45()
{
	Vehicle *mycar = new Vehicle();
	EventHandler* eh = new EventHandler(mycar);
	DrivingMode* dm = new ComportDrivingMode();
	eh->changeDrivingMode(dm);

	delete mycar;
	delete eh;
	delete dm;

	return 0;
}