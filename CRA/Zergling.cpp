#include <iostream>
using namespace std;

class Zergling
{
	// 서버코드
public:
	// 함수를 위에 두는게 C++스타일
	void attack(void)
	{
		hp -= 10;
		mp += 5;
	}

	void move(void)
	{
		hp += 10;
		mp -= 3;
	}
	void status()
	{
		cout << hp << " " << mp << endl;
	}

public:
	int hp = 100;
	int mp = 100;
};

int main7()
{
	// Client 코드
	// heap영역에서 alloc
	Zergling * z1 = new Zergling();
	Zergling * z2 = new Zergling();

	z1->attack();
	z1->move();
	z1->move();
	z1->status();

	z2->status();

	// new한 코드 블록에서 delete하여 release
	delete z1;
	delete z2;

	// stack영역(자동변수) : scope이 끝나는 곳에서 자동 release
	//Zergling z3(); // 함수 선언과 같음
	Zergling z3;
	Zergling z4{};
	z3.attack();
	z3.status();
	z4.attack();
	z4.status();

	return 0;
}
