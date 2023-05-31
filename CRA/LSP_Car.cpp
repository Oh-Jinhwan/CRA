// LSP (리스코프 Principle)
#include <exception>
#include <string>
#include "LSP_Vehicle.cpp"

using namespace std;

class Car : public Vehicle {
public:
    void ChangeGear(Gear gear) override {
        if (Gear::R == gear && GetGear() == Gear::D) {
            //string exception_msg = string("Can't change to REVERSE gear when ") + GetGearName(gear) + string(" gear is engaged!");
            //throw exception(exception_msg.c_str());
            gear = Gear::P;
        }
        else if (Gear::D == gear && GetGear() == Gear::R)
        {
            gear = Gear::P;
        }
        Vehicle::ChangeGear(gear);
    }
};

void ChangeGear(Vehicle *p)
{
    p->ChangeGear(Gear::R);
    p->ChangeGear(Gear::D);
}

int main(int argc, char* argv[])
{
    ChangeGear(new Car());
    return 0;
}
