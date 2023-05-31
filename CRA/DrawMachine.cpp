#include<iostream>
#include<vector>
using namespace std;

// ����ü�� �ձ��ڴ� �빮�ڷ�
struct Position2D
{
	int x;
	int y;
};

class Screen
{
	// public�� ������
public:
	// �Լ��� ����� ���(������) ��������
	void addPosition(Position2D position)
	{
		_mvPosition2D.push_back(position);
	}

	void drawPosition()
	{
		// ������ �ҰŶ�� const��
		for (const Position2D position2D : _mvPosition2D)
		{
			cout << position2D.x << " " << position2D.y << endl;
		}
	}

	// private�� �� �Ʒ���
	// member������ �տ� m������
private:
	vector<Position2D> _mvPosition2D;
};


int main4()
{

	return 0;
}