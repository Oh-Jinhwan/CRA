#include<iostream>
#include<vector>
using namespace std; 

// 함수명, 변수명 의미가 나타나도록 변경(ctrl+RR)
// 밖에서 볼때 함수명만 보고도 어떤 함수인지 알 수 있도록
// 함수의 이름이 적당히 길어져도 된다.
// 0일때 특별한 이유
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