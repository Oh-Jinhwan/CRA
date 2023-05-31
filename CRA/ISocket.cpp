#include <iostream>
using namespace std;

// ���� �������̽�, �ν��Ͻ� ������ ����(����). ���Ӻ�(�������̽�)�� ����, �����δ� �������� ����.
// Ȯ�� ������ ����, ǥ��ȭ��Ŵ
// C++�� interfaceŰ���尡 ��� Ŭ������ �տ� 'I'�� ���� �������̽����� ǥ��
class ISocket
{
public:
	virtual void plugIn() = 0; // ���������Լ� pure virtual function
	virtual void unPlug() = 0; // �����ΰ� ���� ������ �ν��Ͻ� ���� �Ұ���(�ڽĿ��� �ݵ�� �����ؾ���)
};


class Sumsung : public ISocket
{
	//���⿡ ���� �����Լ��� �����θ� �����.
public :
	virtual void plugIn() override; 
	void unPlug(); // virtual�� override�� �Ⱥ����� ��.

private:
	void disable330v();
	void enable330v();
};

class Sunpower : public ISocket
{
public:
	virtual void plugIn() override
	{
		enableSun();
	}
	void unPlug()
	{
		disableSun();
	}

private:
	void disableSun()
	{
		cout << "sun disable" << endl;

	}
	void enableSun()
	{
		cout << "sun enable" << endl;
	}
};

class Dansang : public ISocket
{
public:
	virtual void plugIn() override
	{
		enableDansang();
	}
	void unPlug()
	{
		disableDansang();
	}

private:
	void disableDansang()
	{
		cout << "Dansang disable" << endl;

	}
	void enableDansang()
	{
		cout << "Dansang enable" << endl;
	}
};

void Sumsung::plugIn()
{
	enable330v();
}

void Sumsung::unPlug()
{
	disable330v();
}

void Sumsung::enable330v()
{
	cout << "enable330" << endl;
}

void Sumsung::disable330v()
{
	cout << "disable330v" << endl;

}

void client(ISocket *sc)
{
	sc->plugIn();
	sc->unPlug();
}

int main11()
{
	// ISocket* sc = new ISocket(); // �ν��Ͻ� �����Ұ���
	ISocket *sc = new Sumsung();
	client(sc);
	delete sc;
	sc = nullptr;

	sc = new Sunpower();
	client(sc);
	delete sc;
	sc = nullptr;

	sc = new Dansang();
	client(sc);
	delete sc;
	sc = nullptr;

	cout << endl;
	int a = 3;
	auto ptr = make_unique<int>(a);
	*ptr = 4;
	unique_ptr<int> ptr2;
	unique_ptr<Dansang> ptr3 = make_unique<Dansang>(*(new Dansang()));
	ptr3->plugIn();
	// unique_ptr : �޸� �ڵ� release

	return 0;
}
