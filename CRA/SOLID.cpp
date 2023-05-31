#include <iostream>
#include <vector>
#define interface struct
using namespace std;
// https://github.com/mincoding1/SOLID/tree/main

interface INTER
{
public:
	virtual void gogo() = 0;
};

class BASE2 : public INTER
{
public:
	void gogo() override {
		cout << "hello"; // relization 관계
	}
};


class SUPER
{
public :
	virtual void go() {
		cout << "hello";
	}
};


class BASE1 : public SUPER
{
public :
	void go() override {
		cout << "hello"; // generalization 관계
	}
};

class Coffe
{
public:
	int value = 0;
};

class Person
{
	Coffe* a;
	Coffe* b;
	Coffe* c;
	Person()
	{
		a = new Coffe(); // composition관계 (a와 Person의 life cycle을 같이함)
	}
	Person(Coffe *d)
	{
		b = d; // aggregation 관계 (d와 Person의 life cycle이 관련없음)
	}
	void drink(Coffe *d)
	{
		c = d; // association관계 (d와 Person의 life cycle이 관련없음. 그리고 drink메소드가 호출안될 수 도 있음)
	}
	int drink2(Coffe d)
	{
		return d.value; // dependency관계 (d가 임시로 생성되고 바로 소멸됨)

	}
};