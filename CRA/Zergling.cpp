#include <iostream>
using namespace std;

class Zergling
{
	// �����ڵ�
public:
	// �Լ��� ���� �δ°� C++��Ÿ��
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
	// Client �ڵ�
	// heap�������� alloc
	Zergling * z1 = new Zergling();
	Zergling * z2 = new Zergling();

	z1->attack();
	z1->move();
	z1->move();
	z1->status();

	z2->status();

	// new�� �ڵ� ��Ͽ��� delete�Ͽ� release
	delete z1;
	delete z2;

	// stack����(�ڵ�����) : scope�� ������ ������ �ڵ� release
	//Zergling z3(); // �Լ� ����� ����
	Zergling z3;
	Zergling z4{};
	z3.attack();
	z3.status();
	z4.attack();
	z4.status();

	return 0;
}
