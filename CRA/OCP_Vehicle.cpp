// Open/Closed Principle

#define interface struct
interface DrivingMode {
	virtual int GetPower() = 0;
	virtual int GetSuspendHeight() = 0;
};

class SportDrivingMode : public DrivingMode
{
public:
	int GetPower() override { return 500; }
	int GetSuspendHeight() override { return 10; }
};

class ComportDrivingMode : public DrivingMode
{
public:
	int GetPower() override { return 400; }
	int GetSuspendHeight() override { return 20; }
};

class EnonomyDrivingMode : public DrivingMode
{
public:
	int GetPower() override { return 400; }
	int GetSuspendHeight() override { return 20; }
};

class Vehicle {
public:
	int GetPower() {
		return power_;
	}

	int GetSuspensionHeight() {
		return suspension_height_;
	}

	void SetPower(int power) {
		power_ = power;
	}

	void SetSuspensionHeight(int suspension_height) {
		suspension_height_ = suspension_height;
	}

private:
	int power_;
	int suspension_height_;
};