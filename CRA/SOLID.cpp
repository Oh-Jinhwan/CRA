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
		cout << "hello"; // relization ����
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
		cout << "hello"; // generalization ����
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
		a = new Coffe(); // composition���� (a�� Person�� life cycle�� ������)
	}
	Person(Coffe *d)
	{
		b = d; // aggregation ���� (d�� Person�� life cycle�� ���þ���)
	}
	void drink(Coffe *d)
	{
		c = d; // association���� (d�� Person�� life cycle�� ���þ���. �׸��� drink�޼ҵ尡 ȣ��ȵ� �� �� ����)
	}
	int drink2(Coffe d)
	{
		return d.value; // dependency���� (d�� �ӽ÷� �����ǰ� �ٷ� �Ҹ��)

	}
};