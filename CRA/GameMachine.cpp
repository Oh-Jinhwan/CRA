#include <iostream>
using namespace std;

class GameMachine
{
public :
	void inputCoin(int nInsertCoin);
	void playGame();
	void printRemianCoin() const; // 멤버변수 변경 불가

private:
	int nCoin;
};

void GameMachine::inputCoin(int nInsertCoin)
{
	if (nCoin + nInsertCoin  <= 10)
	{
		nCoin += nInsertCoin;
	}
	else
	{
		cout << "can not input" << endl;
	}
}

void GameMachine::playGame()
{
	if (nCoin > 0)
	{
		cout << "play" << endl;
		nCoin--;
	}
	else
	{
		cout << "insertCoint Please" << endl;
	}
}

void GameMachine::printRemianCoin() const
{
	cout << nCoin << endl;
}


int main9()
{
	GameMachine* gm = new GameMachine();

	gm->playGame();
	gm->printRemianCoin();

	gm->inputCoin(2);
	gm->printRemianCoin();
	gm->playGame();
	gm->printRemianCoin();
	gm->playGame();

	gm->playGame();
	gm->printRemianCoin();

	gm->inputCoin(11);
	gm->printRemianCoin();

	return 0;
}
