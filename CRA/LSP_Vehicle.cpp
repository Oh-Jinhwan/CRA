// LSP (리스코프 Principle)
#include <string>
#pragma once

// enum과 사용법은 동일하나, 자동캐스팅이 안됨(명확하게 사용해야함)
enum class Gear {
	P, //Parking
	R, //Reverse
	N, //Neutral
	D, //Drive
};

class Vehicle {
public:
	Gear GetGear() {
		return gear_;
	}

	virtual void ChangeGear(Gear gear) {
		gear_ = gear;
	}

	std::string GetGearName(Gear gear) {
		if (gear == Gear::P) return "Parking";
		if (gear == Gear::R) return "Reverse";
		if (gear == Gear::N) return "Neutral";
		if (gear == Gear::D) return "Drive";
	}

private:
	Gear gear_ = Gear::P; //뒤에 under bar붙히면 멤버 변수라는 뜻
};