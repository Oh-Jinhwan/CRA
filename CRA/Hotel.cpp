#include<iostream>
#include<vector>
using namespace std; 

// �Լ���, ������ �ǹ̰� ��Ÿ������ ����(ctrl+RR)
// �ۿ��� ���� �Լ��� ���� � �Լ����� �� �� �ֵ���
// �Լ��� �̸��� ������ ������� �ȴ�.
// 0�϶� Ư���� ����
void run(vector<int>& theVector) {
	for (unsigned t = 0; t < theVector.size(); t++) {
		if (theVector[t] == 0) continue;
		theVector[t] = theVector[t] - 1;
	}
}

bool isEmpty(int nLeftRoomDay);

bool isEmpty(int nLeftRoomDay)
{
	const int EMPTY = 0;

	return (nLeftRoomDay == EMPTY);
}

void ElapseOneDay(vector<int>& vnLeftRoomDays)
{
	for (unsigned nRoomNumber = 0; nRoomNumber < vnLeftRoomDays.size(); nRoomNumber++)
	{
		if(isEmpty(vnLeftRoomDays[nRoomNumber]))
		{
			continue;
		}
		vnLeftRoomDays[nRoomNumber] -= 1;
	}
}


int main3()
{

	return 0; 
} 