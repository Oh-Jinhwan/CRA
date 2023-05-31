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
	virtual void msg() override; // virtual�� override(�Լ��̸� ��Ÿ������ Ȯ�ο�)�� �Ⱥ�������
	// ���� virtual �Լ� ���� ���ϸ� �θ� ȣ���.

	void isSmart(void)
	{
		cout << "this is smart" << endl;
	}
};

// �������̵�
void SmartPhone::call(void)
{
	cout << "SmartCalling..." << endl;
	//a = 4; //�θ��� private�� ���� �Ұ���
	b = 5; //�θ��� protected�� ���ٰ���
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
	// ������ Ȱ���Ͽ�, � Ŭ�������� Ȯ���� �ʿ� ����
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
	//SmartPhone* c = new Phone(); // �Ұ���
	SmartPhone* d = new SmartPhone();

	a->call(); // �θ��� call ȣ��
	b->call(); // �θ��� call ȣ�� (virtual �ƴ�)
	//c->call();
	d->call(); // �ڽ��� call ȣ��

	a->msg(); // �θ��� msg ȣ��
	b->msg(); // �ڽ��� msg ȣ�� (virtual) -> ��Ÿ�Ӷ� ������ �ٲܼ��ִ�.(� �ڽ��� ���Ƴ���Ŀ� ���� �ٸ�. new�Ҷ� �����Լ� ���̺��� �������)
	// c->msg();
	d->msg(); // �ڽ��� msg ȣ��

	usePhone(a); // �θ��� msg ȣ��
	usePhone(b); // �ڽ��� msg ȣ��

	delete a;
	delete b;
	//delete c;
	delete d;
	cout << endl;
	//////////////////////////////////////////////////////
	SmartPhone* e = (SmartPhone *)new Phone();
	e->call(); //�ڽ��� callȣ�� 
	e->msg(); //�θ��� msgȣ�� (virtual) -> new�Ҷ� �����Լ� ���̺��� �������

	e->isSmart(); //�ڽ��� isSmartȣ��

	delete e;

	return 0;
}
