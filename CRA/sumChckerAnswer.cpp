// https://gist.github.com/mincoding1/ee341fd0bed5627d1d2bdb9f04878c1a

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class SumChecker {
public:
	string GetResult(string str) {
		if (isError(str)) return "ERROR";
		if (isPass(str)) return "PASS";
		return "FAIL";
	}

private:
	bool isError(const string& str) {
		if (isInvalidPositionOfOperator(str)) return true;
		if (isNotOnlyOneOperator(str)) return true;
		if (isIncludeObnormalChar(str)) return true;
		return false;
	}

	bool isInvalidPositionOfOperator(const string& str) {
		int p1 = str.find('+');
		int p2 = str.find('=');
		if (p1 >= p2) return true;
		if (p1 < 1) return true;
		if (p2 < 3) return true;
		if (p2 >= str.length() - 1) return true;

		return false;
	}

	bool isNotOnlyOneOperator(const string& str) {
		if (getCount(str, '+') != 1) return true;
		if (getCount(str, '=') != 1) return true;
		return false;
	}

	int getCount(const string& str, char target) {
		int result = 0;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == target) {
				result++;
			}
		}
		return result;
	}

	bool isIncludeObnormalChar(const string& str) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '+') continue;
			if (str[i] == '=') continue;
			if (str[i] >= '0' && str[i] <= '9') continue;
			return true;
		}
		return false;
	}

	bool isPass(string str) {
		int p1 = str.find('+');
		int p2 = str.find('=');

		int num1 = stoi(str.substr(0, p1));
		int num2 = stoi(str.substr(p1 + 1, p2 - p1 - 1));
		int num3 = stoi(str.substr(p2 + 1));

		if (num1 + num2 == num3) return true;
		return false;
	}
};