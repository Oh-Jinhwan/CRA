#include<iostream>
#include<vector>
using namespace std;

// 구조체의 앞글자는 대문자로
struct Position2D
{
	int x;
	int y;
};

class Screen
{
	// public은 맨위로
public:
	// 함수는 동사와 명사(목적어) 조합으로
	void addPosition(Position2D position)
	{
		_mvPosition2D.push_back(position);
	}

	void drawPosition()
	{
		// 참조만 할거라면 const로
		for (const Position2D position2D : _mvPosition2D)
		{
			cout << position2D.x << " " << position2D.y << endl;
		}
	}

	// private는 맨 아래로
	// member변수는 앞에 m붙히기
private:
	vector<Position2D> _mvPosition2D;
};


int main4()
{

	return 0;
}