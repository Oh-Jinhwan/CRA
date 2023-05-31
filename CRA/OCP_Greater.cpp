// Open/Closed Principle
#include <string>
#include <iostream>
#define interface struct
// public을 생략하기 위해 struct를 사용한다
// struct는 기본값이 public이기 때문이다.
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
	Greeter* g = new Greeter(gm); // 밖에서 instance 만들어 주입(dependency injection)

	cout << g->Greet() << endl;

	delete gm;
	delete g;

	return 0;
}
