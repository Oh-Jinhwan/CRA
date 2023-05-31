#include <iostream>
#include <vector>
using namespace std;

// https://vo.la/kqsHR
// https://gist.github.com/mincoding-jh/413460a4ee8acca490d4249e59237c52
// 인터페이스, 함수 시그니쳐 (이름, 파라미터 들)
void bbq(int val1, int val2)
{
	cout << "bbq1" << endl;
}

// 함수 오버로딩
void bbq(char a, char b)
{
	cout << "bbq2" << endl;
}

int getSum(int a2, int b2);

int getSum(int a45, int b2)
{
	return a45 + b2;
}

int main2()
{
	int a2 = 1;
	int b2 = 2;
	int d = getSum(a2, b2);

	for (int i = 0; i < 10; ++i)
	{
		cout << "HI";
	}

	// Ctrl + Shift + R : refactor this

	// Alt + Enter : QuickFix (자동으로 include 추천, for each문으로 바꾸기 등)
	// Ctrl + Space : 자동완성 (자동으로 include 경로 추천)

	// ctrl + R + R : rename
	// ctrl + alt + enter : reformat code (자동 들여쓰기)
	// ctrl + alt + shift + up/down : 코드 이동시키기

	// ctrl + D : 한줄 copy
	// alt 누르고 줄 드래그 : 여러줄 동시 커서
	// alt + shift 누르고 줄 드래그 : 한번에 바꾸기
	// ctrl + shift + enter : 코드자동완성

	int a = 0;

	cout << "hello world";
	//cin >> a;
	cout << a;

	if (a > 3)
	{
		cout << "hi" << endl;
	}
	else if (a > 1)
	{
		cout << "hello" << endl;
	}
	else
	{
		// do nothing
	}

	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
	}
	cout << endl;

	// 정적 배열 (스택)
	int arr[10] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	for (const int val : arr) // val은 수정 불가
	{
		cout << val << " ";
	}
	cout << endl;

	for (int val : arr) // val은 원본 arr에 영향없음
	{
		val = 10;
		cout << val << " ";
	}
	cout << endl;

	for (int val : arr) // 원본 arr그대로 출력
	{
		cout << val << " ";
	}
	cout << endl;

	for (int& val : arr) // val에 의해 원본 값 바뀜
	{
		cout << val << " ";
		val = 10;
	}

	cout << endl;
	for (int& val : arr)
	{
		cout << val << " ";
	}
	cout << endl;

	// 동적배열 (힙)
	vector<int> vA; // 자동초기화

	vA.push_back(3);
	vA.push_back(2);
	vA.push_back(1);

	for (int i = 0; i < 20; i++)
	{
		vA.push_back(i); // 메모리 늘림
	}
	cout << vA.size() << endl;

	for (const int val : vA)
	{
		cout << val << " ";
	}
	cout << endl;

	for (int i = 0; i < 20; i++)
	{
		vA.pop_back(); // 메모리 감소시킴
	}
	cout << vA.size() << endl;


	int* rArr;

	rArr = (int*)malloc(sizeof(int) * 10);
	free(rArr);

	// 함수 호출
	bbq(2, 3);
	bbq('a', 'b');

	// 아래 두개는 동일
	int const INF = 123;
	const int INF2 = 123;

	// INF = 3; // 수정 불가
	// INF2 = 3; // 수정불가

	int aa = 10;
	int bb = 20;
	int* const ptr = &aa; // int *에 대해 const가 붙음
	// ptr = &bb; // 주소값 변경 불가

	int const * pptr = &bb; // int에 대해 const가 붙음
	//*pptr = 100; // 역참조 값 변경 불가

	return 0;
}
