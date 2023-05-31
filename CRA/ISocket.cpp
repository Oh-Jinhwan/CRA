#include <iostream>
using namespace std;

// 소켓 인터페이스, 인스턴스 만들지 않음(못함). 접속부(인터페이스)만 있지, 구현부는 존재하지 않음.
// 확장 가능한 형태, 표준화시킴
// C++은 interface키워드가 없어서 클래스명 앞에 'I'를 붙혀 인터페이스임을 표시
class ISocket
{
public:
	virtual void plugIn() = 0; // 순수가상함수 pure virtual function
	virtual void unPlug() = 0; // 구현부가 없기 때문에 인스턴스 생성 불가능(자식에서 반드시 구현해야함)
};


class Sumsung : public ISocket
{
	//여기에 순수 가상함수의 구현부를 만든다.
public :
	virtual void plugIn() override; 
	void unPlug(); // virtual과 override는 안붙혀도 됨.

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
	// ISocket* sc = new ISocket(); // 인스턴스 생성불가능
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
	// unique_ptr : 메모리 자동 release

	return 0;
}
