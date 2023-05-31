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
    // 특정 클래스 대신 인터페이스를 둬서 의존성을 낮춤
    Vehicle *vehicle_;
};