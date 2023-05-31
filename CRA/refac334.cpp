#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::string;
using std::vector;

class SplitAndSum {
public:
	int splitAndSum2(string text)
	{
		if (isEmpty(text)) return 0;

		return  getSum(toInts(split(text)));
	}

private:
	bool isEmpty(string text)
	{
		return text.empty();
	}

	vector<string> split(string& text)
	{
		vector<string> values;
		int a = 0, b = 0;

		text += "-";
		while (1) {
			b = text.find("-", a);
			if (b == -1) break;
			string temp = text.substr(a, b - a);
			values.push_back(temp);
			a = b + 1;
		}

		return values;
	}

	vector<int> toInts(vector<string> values)
	{
		vector<int> result;

		for (auto& value : values)
		{
			result.push_back(stoi(value));
		}

		return result;
	}

	int getSum(vector<int> nums)
	{
		int result = 0;

		for (auto& num : nums)
		{
			result += num;
		}

		return result;
	}
};

int main33()
{
	cout << SplitAndSum().splitAndSum2("100-10-20");
	return 0;
}