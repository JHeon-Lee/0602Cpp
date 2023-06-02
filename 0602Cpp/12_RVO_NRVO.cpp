#include <iostream>

using namespace std;

/*
	최적화 방법
	RVO : Return Value Opptimization

	NRVO : Named Return Value Opptimization
*/

class Test
{
	int value1;
	int value2;

public:
	static int count;

public:
	Test(int value) : value1(value), value2(count++)
	{
		cout << "constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	Test(const Test& rhs) : value1(rhs.value1), value2(count++)
	{
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	~Test()
	{
		cout << "destructor : " << this->value1 << ", " << this->value2 << endl;
	}
};

int Test::count = 1;

Test MakeRVO(int value)
{
	return Test(value);
}

Test MakeNRVO(int value)
{
	Test test(value); // 익명객체 생성
	return test; // 복사생성자
}

int main()
{
	cout << "---RVO---" << endl;
	Test t1 = MakeRVO(1);

	cout << "---NRVO---" << endl; // release 모드에서는 복사생성자 없이 rvo로 변경됨 --> 컴파일러의 최적화
	Test t2 = MakeNRVO(2);

	return 0;
}