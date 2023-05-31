// DIP(Dependency Inversion Principle)
#include "DIP_RacingCar.cpp"

class Pilot {
public:
    Pilot(Vehicle *vehicle_) {
        this->vehicle_ = vehicle_;
    }

    void IncreaseSpeed() {
        vehicle_->Accelerate();
    }

private:
    // Ư�� Ŭ���� ��� �������̽��� �ּ� �������� ����
    Vehicle *vehicle_;
};