#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& arr);

class ISortAlgorithm
{
public:
	virtual void RunSort(vector<int>& arr) = 0;
};

class BubbleSortAlgorithm : public ISortAlgorithm
{
public :
	virtual void RunSort(vector<int>& arr) override;
};

class SelectionSortAlgorithm : public ISortAlgorithm
{
public:
	virtual void RunSort(vector<int>& arr) override;
};

class SortMachine
{
public:
	typedef enum
	{
		eSORT_ALGO_BUBBLE,
		eSORT_ALGO_SELECTION,
	} SORT_ALGO;
	void insert(int val)
	{
		arr.push_back(val);
	}
	void selection(SORT_ALGO eSort);// 파라미터는 자유
	void run(); // 내가 선택한 알고리즘이 동작
	void show()
	{
		print(arr);
	}
	~SortMachine()
	{
		delete sortAlgorithm;
	}
	SortMachine()
	{
		sortAlgorithm = createAlgo(eSORT_ALGO_BUBBLE);
	}

private:
	vector<int> arr;
	ISortAlgorithm * sortAlgorithm = nullptr;

	// 가상 생성자
	ISortAlgorithm * createAlgo(SORT_ALGO eSort)
	{
		ISortAlgorithm* algo = nullptr;

		if (eSort == eSORT_ALGO_BUBBLE)
		{
			algo = new BubbleSortAlgorithm();
		}
		else if (eSort == eSORT_ALGO_SELECTION)
		{
			algo = new SelectionSortAlgorithm();
		}

		return algo;
	}
};


void SortMachine::run()
{
	if (this->sortAlgorithm != nullptr)
	{
		this->sortAlgorithm->RunSort(this->arr);
	}
}

void SortMachine::selection(SORT_ALGO eSort)
{
	if (this->sortAlgorithm != nullptr)
	{
		delete this->sortAlgorithm;
		this->sortAlgorithm = nullptr;
	}

	this->sortAlgorithm = createAlgo(eSort);
}

void bubbleSort(vector<int>& arr)
{
	for (unsigned int a = 0; a < arr.size(); a++)
	{
		for (unsigned int b = 0; b < arr.size() - 1 - a; b++)
		{
			if (arr[b] > arr[b + 1])
			{
				std::swap(arr[b], arr[b + 1]);
			}
		}
	}
}
void seletionSort(vector<int>& arr)
{
	for (unsigned int a = 0; a < arr.size(); a++)
	{
		for (unsigned int b = a + 1; b < arr.size(); b++)
		{
			if (arr[a] > arr[b])
			{
				std::swap(arr[a], arr[b]);
			}
		}
	}
}

void print(vector<int>& arr)
{
	for (const int& val : arr)
	{
		cout << val << " ";
	}
	cout << endl;
}

void BubbleSortAlgorithm::RunSort(vector<int>& arr)
{
	bubbleSort(arr);
}

void SelectionSortAlgorithm::RunSort(vector<int>& arr)
{
	seletionSort(arr);
}

int main22()
{
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(7);
	arr.push_back(1);
	arr.push_back(5);
	arr.push_back(2);

	//bubbleSort(arr);
	seletionSort(arr);
	print(arr);

	SortMachine* sMachine = new SortMachine();

	sMachine->selection(SortMachine::eSORT_ALGO_BUBBLE);
	sMachine->insert(3);
	sMachine->insert(7);
	sMachine->insert(9);
	sMachine->insert(5);
	sMachine->insert(2);
	sMachine->run();
	sMachine->show();

	sMachine->selection(SortMachine::eSORT_ALGO_SELECTION);
	sMachine->insert(1);
	sMachine->run();
	sMachine->show();

	delete sMachine;

	return 0;
}
