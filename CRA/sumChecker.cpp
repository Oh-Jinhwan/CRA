#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Component
{
	int plusCount = 0;
	int equalCount = 0;
	int plusPos, equlPos = 0;
};

class SumChecker
{
public:
	string GetResult(const string inputStr)
	{
		Component component;
		if (makeComponent(inputStr, component))
		{
			if (validateComponent(inputStr, component))
			{
				if (checkSum(inputStr, component)) return "PASS";
				return "FAIL";
			}
		}
		return "ERROR";
	}

private:
	bool makeComponent(const string str, Component& stComInfo)
	{
		//+와 = 개수 확인
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '+') {
				stComInfo.plusCount++;
				stComInfo.plusPos = i;
			}
			else if (str[i] == '=') {
				stComInfo.equalCount++;
				stComInfo.equlPos = i;
			}
			else if (!(str[i] >= '0' && str[i] <= '9')) {
				return false;
				break;
			}
		}
		return true;
	}

	bool validateComponent(const string str, const Component& stComInfo)
	{
		if (stComInfo.plusCount == 1 && stComInfo.equalCount == 1 && stComInfo.plusPos < stComInfo.equlPos)
		{
			if (stComInfo.plusPos >= 1 && stComInfo.equlPos >= 3 && stComInfo.equlPos < str.length() - 1)
			{
				return true;
			}
		}
		return false;
	}

	bool checkSum(const string str, const Component stComInfo)
	{
		int leftValue1 = stoi(str.substr(0, stComInfo.plusPos));
		int leftValue2 = stoi(str.substr(stComInfo.plusPos + 1, stComInfo.equlPos - stComInfo.plusPos - 1));
		int rightValue = stoi(str.substr(stComInfo.equlPos + 1));

		if (leftValue1 + leftValue2 == rightValue)
		{
			return true;
		}
		return false;
	}

};

int main44()
{
	//25+61=100
	//1 ~ 5자리수 덧셈 수식이 맞는지 확인하는 프로그램
	//띄어쓰기 없음

	string str = "25+61=86"; //PASS
	//string str = "12345+12345=24690"; //PASS
	//string str = "5++5=10"; //ERROR
	//string str = "10000+1=10002"; //FAIL

	cout << SumChecker().GetResult(str);

	return 0;
}