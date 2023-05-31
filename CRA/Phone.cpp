#include <iostream>
using namespace std;

class Phone
{
public:
	void call(void);
	virtual void msg();

private:
	int a = 3;

protected:
	int b = 3;
};

void Phone::call(void)
{
	cout << "calling" << endl;
}

void Phone::msg()
{
	cout << "messaging" << endl;
}

class SmartPhone : public Phone
{
public:
	void call(void);
	void internet(void);
	virtual void msg() override; // virtual과 override(함수이름 오타있을때 확인용)는 안붙혀도됨
	// 만약 virtual 함수 정의 안하면 부모께 호출됨.

	void isSmart(void)
	{
		cout << "this is smart" << endl;
	}
};

// 오버라이딩
void SmartPhone::call(void)
{
	cout << "SmartCalling..." << endl;
	//a = 4; //부모의 private는 접근 불가능
	b = 5; //부모의 protected는 접근가능
}

void SmartPhone::internet()
{
	cout << "connecting..." << endl;
}

void SmartPhone::msg()
{
	cout << "smart messaging" << endl;
}

void usePhone(Phone *p)
{
	// 다형성 활용하여, 어떤 클래스인지 확인할 필요 없음
	p->msg();
}

int main10()
{
	Phone *p = new Phone();
	SmartPhone* sp = new SmartPhone();

	p->call();
	sp->call();
	sp->internet();

	delete p;
	delete sp;
	cout << endl;
	//////////////////////////////////////////////////////
	Phone* a = new Phone();
	Phone* b = new SmartPhone();
	//SmartPhone* c = new Phone(); // 불가능
	SmartPhone* d = new SmartPhone();

	a->call(); // 부모의 call 호출
	b->call(); // 부모의 call 호출 (virtual 아님)
	//c->call();
	d->call(); // 자식의 call 호출

	a->msg(); // 부모의 msg 호출
	b->msg(); // 자식의 msg 호출 (virtual) -> 런타임때 동작을 바꿀수있다.(어떤 자식을 갈아끼우냐에 따라 다름. new할때 가상함수 테이블을 만들어줌)
	// c->msg();
	d->msg(); // 자식의 msg 호출

	usePhone(a); // 부모의 msg 호출
	usePhone(b); // 자식의 msg 호출

	delete a;
	delete b;
	//delete c;
	delete d;
	cout << endl;
	//////////////////////////////////////////////////////
	SmartPhone* e = (SmartPhone *)new Phone();
	e->call(); //자식의 call호출 
	e->msg(); //부모의 msg호출 (virtual) -> new할때 가상함수 테이블을 만들어줌

	e->isSmart(); //자식의 isSmart호출

	delete e;

	return 0;
}
