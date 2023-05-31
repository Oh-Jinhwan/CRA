// IPS(Interface Segregation Principle)
#include <string>
#include <exception>
#include "IPS_Bird.cpp";
using namespace std;

class Penguin : public Bird {
public:
	Penguin(int initial_feather_count) {
		number_of_feathers_ = initial_feather_count;
	}

	void Molt() override {
		number_of_feathers_ -= 1;
	}

	// 구현할 필요 없음
	//void Fly() override {
	//	throw exception("Unsupported Operation Exception");
	//}

	void swim() {
		current_location_ = "in the water";
	}

private:
	string current_location_;
	int number_of_feathers_;
};