// Open/Closed Principle
#include <string>
#include <iostream>
#define interface struct
// public�� �����ϱ� ���� struct�� ����Ѵ�
// struct�� �⺻���� public�̱� �����̴�.
using namespace std;

interface GreeterMan
{
public:
	virtual string Greet() = 0;
};
class Greeter {
public:
	Greeter (GreeterMan * gm)
	{
		this->gm = gm;
	}
	string Greet() {
		if (gm != nullptr) return gm->Greet();
		else return "Hello.";
	}

	void SetGreeterMan(GreeterMan * gm) {
		this->gm = gm;
	}

private:
	GreeterMan* gm = nullptr;
};


class FormalGreeterMan : public GreeterMan
{
public:
	virtual string Greet() override
	{
		return "Good evening, sir.";
	}
};

class CasualGreeterMan : public GreeterMan
{
public :
	virtual string Greet() override
	{
		return "Sup bro?";

	}
};

class IntimateGreeterMan : public GreeterMan
{
public:
	virtual string Greet() override
	{
		return "Hello Darling!";
	}
};

class NormalGreeterMan : public GreeterMan
{
public:
	virtual string Greet() override
	{
		return "Hello!";
	}
};

int main33(int argc, char* argv[])
{
	GreeterMan *gm = new CasualGreeterMan();
	Greeter* g = new Greeter(gm); // �ۿ��� instance ����� ����(dependency injection)

	cout << g->Greet() << endl;

	delete gm;
	delete g;

	return 0;
}
