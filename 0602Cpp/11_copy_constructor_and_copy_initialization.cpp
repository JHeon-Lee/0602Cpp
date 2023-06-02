#include <iostream>

using namespace std;

class Test
{
	int num1;
	int num2;

public:
	Test() {}
	Test(int n1,int n2) : num1(n1), num2(n2) {}
};

class Fraction
{
public:
	Fraction() {}

	// 이런 생성자를 만들어두면 위의 생성자는 가려짐
	Fraction(int num = 0, int den = 0) : numerator(num), denominator(den)
	{
		cout << "constructor!!" << endl;
	}

	// 복사 생성자 - 기본 생성자처럼 자동으로 만들어짐
	Fraction(const Fraction& fraction)
	{
		cout << "copy constructor" << endl;
	}

	// 복사 대입 연산자 - 기본 생성자처럼 자동으로 만들어짐 ( 이동 생성자, 이동대입 연산자, 소멸자 총 6개)
	Fraction& operator= (const Fraction& rhs)
	{
		cout << "copy assignment operator" << endl;
		return *this;
	}

private:
	int numerator;
	int denominator;
};

Fraction CreateFraction()
{
	Fraction temp(5, 2); // 생성자
	return temp; // 복사 생성자
}

int main()
{
	Test t1(1, 2);
	Test t2; // Test() {} 없으면 불가능

	Test t3(t1); // copy
	t3 = t2; // 복사 대입

	Fraction frac(3, 5);
	Fraction copy1(frac); // 복사 생성자 --> 복사대입과 안헷갈려서 직관적임
	Fraction copy2 = frac; // 복사 생성자 --> 선언과 동시에 초기화하는 경우는 복사대입이 아님
	copy2 = frac; // 복사 대입 연산자

	CreateFraction();

	return 0;
}