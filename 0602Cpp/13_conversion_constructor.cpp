#include <iostream>

using namespace std;

// 변환 생성자

class Fraction
{
public:
	Fraction() {}

	Fraction(int num, int den) : numerator(num), denominator(den)
	{
		cout << "constructor!!" << endl;
	}

	Fraction(const Fraction& fraction) : numerator(fraction.numerator), denominator(fraction.denominator)
	{
		cout << "copy constructor" << endl;
	}

	Fraction& operator= (const Fraction& rhs)
	{
		cout << "copy assignment operator" << endl;
		return *this;
	}

	/*explicit*/ Fraction(int a) : numerator(a), denominator(1)
	{
		cout << "conversion constructor" << endl;
	}

	friend std::ostream& operator << (ostream& out, const Fraction frac)
	{
		out << frac.numerator << "/ " << frac.denominator << endl;
		return out;
	}

private:
	int numerator;
	int denominator;
};

void PrintFraction(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac1(10, 20);
	Fraction frac2(frac1);

	Fraction frac3(1);
	Fraction frac4('a'); // 다른자료형이 들어와도 형변환 해줘서 호출함
	Fraction frac5(3.14f);

	cout << endl;

	PrintFraction(frac1); // 복사 생성자가 각각 두번 호출된다
	PrintFraction(frac2);
	PrintFraction(frac3);
	PrintFraction(frac4);
	PrintFraction(frac5);

	PrintFraction('A'); // 값이 변환 생성자, 복사 생성자를 거쳐서 들어가게됨
	PrintFraction(3.14f);
	PrintFraction(10);
	// 변환 생성자에 임시객체 만드는걸 막고싶거나, 암시적 형변환을 막고싶다면
	// 변환 생성자 앞에 explicit 자료형을 넣어주면 된다

	Fraction frac6(static_cast<int>('A')); // 가능
	// PrintFraction(static_cast<int>('A')); explicit이 있다면 불가능

	return 0;
}