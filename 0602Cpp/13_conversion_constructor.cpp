#include <iostream>

using namespace std;

// ��ȯ ������

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
	Fraction frac4('a'); // �ٸ��ڷ����� ���͵� ����ȯ ���༭ ȣ����
	Fraction frac5(3.14f);

	cout << endl;

	PrintFraction(frac1); // ���� �����ڰ� ���� �ι� ȣ��ȴ�
	PrintFraction(frac2);
	PrintFraction(frac3);
	PrintFraction(frac4);
	PrintFraction(frac5);

	PrintFraction('A'); // ���� ��ȯ ������, ���� �����ڸ� ���ļ� ���Ե�
	PrintFraction(3.14f);
	PrintFraction(10);
	// ��ȯ �����ڿ� �ӽð�ü ����°� ����Ͱų�, �Ͻ��� ����ȯ�� ����ʹٸ�
	// ��ȯ ������ �տ� explicit �ڷ����� �־��ָ� �ȴ�

	Fraction frac6(static_cast<int>('A')); // ����
	// PrintFraction(static_cast<int>('A')); explicit�� �ִٸ� �Ұ���

	return 0;
}