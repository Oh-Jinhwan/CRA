// IPS(Interface Segregation Principle)

#include <string>
#include "ISP_Bird.cpp";
using namespace std;

// 다중 상속
class Eagle : public Bird, public Flyable {
public:
    Eagle(int initial_feather_count) {
        number_of_feathers_ = initial_feather_count;
    }

    void Fly() override {
        current_location_ = "in the air";
    }

    void Molt() override {
        number_of_feathers_ -= 1;
    }

private:
    string current_location_;
    int number_of_feathers_;
};

class Eagle2 : FlyableBird {
public:
    Eagle2(int initial_feather_count) {
        number_of_feathers_ = initial_feather_count;
    }

    void Fly() override {
        current_location_ = "in the air";
    }

    void Molt() override {
        number_of_feathers_ -= 1;
    }

private:
    string current_location_;
    int number_of_feathers_;
};