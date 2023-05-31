#include <iostream>
using namespace std;

class Calculator
{
	// 서버 코드
public:
	void Plus(int val1, int val2)
	{
		result = val1 + val2;
	}
	void Minus(int val1, int val2)
	{
		result = val1 - val2;
	}
	void Devide(int val1, int val2)
	{
		if(val2 != 0)
		{
			result = val1 / val2;
		}
		else
		{
			printError();
		}
	}
	void Multiple(int val1, int val2)
	{
		result = val1 + val2;
	}
	void PrintResult()
	{
		cout << result << endl;
	}

	// // get + 변수수명
	int getResult() const
	{
		// getter에서는 데이터 변경작업 없으므로 const처리
		// result = 3; // 컴파일에러
		return result;
	}

	// int result;
	// puplic 멤버변수는 잘 사용하지 않음.

	// 함수 선언만
	void setNewValue(int a);
private:
	int result;

	void printError()
	{
		cout << "ERROR" << endl;
	}
};

// 함수 구현은 외부에서
void Calculator::setNewValue(int a)
{
	result = a;
}


int main8()
{
	// 클라이언트 코드
	Calculator *cal = new Calculator();

	cal->Plus(1, 2); // 메세지 전달
	cal->PrintResult();
	cal->Minus(1, 2);
	cal->PrintResult();
	cal->Devide(1, 0);
	cal->PrintResult();
	cal->Multiple(1, 2);
	cal->PrintResult();

	int ret = cal->getResult();

	cal->setNewValue(100);
	cal->PrintResult();

	delete cal;

	return 0;
}