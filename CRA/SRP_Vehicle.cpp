// Single Responsibility Principle (SRP)
//�ϳ��� Ŭ������ �ϳ��� å�Ӹ� ������ �Ѵ�
// �ҽ��ڵ� : https://github.com/mincoding1/SOLID/blob/main/cpp/SRP/step1/Vehicle.cpp
// ��� : https://gist.github.com/mincoding1/ee341fd0bed5627d1d2bdb9f04878c1a


class Vehicle {
public:
	Vehicle(int maxFuel) {
		max_fuel_ = maxFuel;
		remaining_fuel_ = maxFuel;
	}

	int GetMaxFuel() {
		return max_fuel_;
	}

	int *GetRemainingFuel() {
		return &remaining_fuel_;
	}

	void SetRemainingFuel(int remaining_fuel) {
		remaining_fuel_ = remaining_fuel;
	}

	void Accelerate() {
		remaining_fuel_--;
	}

private:
	int max_fuel_;
	int remaining_fuel_;
};

class Station
{
public:
	void ReFuel(Vehicle *customer) {
		customer->SetRemainingFuel(customer->GetMaxFuel()); // �����Ͻ� ����
	}

};

class TransSystem
{
public:
	Vehicle *v;
	Station *s;

	TransSystem()
	{
		v = new Vehicle(100);
		s = new Station();
	}

	void run()
	{
		v->Accelerate();
		s->ReFuel(v);
	}
};