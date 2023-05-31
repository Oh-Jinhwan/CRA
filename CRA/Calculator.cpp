#include <iostream>
using namespace std;

class Calculator
{
	// ���� �ڵ�
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

	// // get + ��������
	int getResult() const
	{
		// getter������ ������ �����۾� �����Ƿ� constó��
		// result = 3; // �����Ͽ���
		return result;
	}

	// int result;
	// puplic ��������� �� ������� ����.

	// �Լ� ����
	void setNewValue(int a);
private:
	int result;

	void printError()
	{
		cout << "ERROR" << endl;
	}
};

// �Լ� ������ �ܺο���
void Calculator::setNewValue(int a)
{
	result = a;
}


int main8()
{
	// Ŭ���̾�Ʈ �ڵ�
	Calculator *cal = new Calculator();

	cal->Plus(1, 2); // �޼��� ����
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