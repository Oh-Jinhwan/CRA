// (DIP)Dependency Inversion Principle
#define interface struct

interface Vehicle
{
    virtual void Accelerate() = 0;
};

class RacingCar : public Vehicle {
public:
    RacingCar(int max_fuel) {
        max_fuel_ = max_fuel;
        remaining_fuel_ = max_fuel;
    }

    void Accelerate() {
        power_++;
        remaining_fuel_--;
    }

private:
    int max_fuel_;
    int remaining_fuel_;
    int power_;
};