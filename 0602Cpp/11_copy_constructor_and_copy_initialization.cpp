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

	// �̷� �����ڸ� �����θ� ���� �����ڴ� ������
	Fraction(int num = 0, int den = 0) : numerator(num), denominator(den)
	{
		cout << "constructor!!" << endl;
	}

	// ���� ������ - �⺻ ������ó�� �ڵ����� �������
	Fraction(const Fraction& fraction)
	{
		cout << "copy constructor" << endl;
	}

	// ���� ���� ������ - �⺻ ������ó�� �ڵ����� ������� ( �̵� ������, �̵����� ������, �Ҹ��� �� 6��)
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
	Fraction temp(5, 2); // ������
	return temp; // ���� ������
}

int main()
{
	Test t1(1, 2);
	Test t2; // Test() {} ������ �Ұ���

	Test t3(t1); // copy
	t3 = t2; // ���� ����

	Fraction frac(3, 5);
	Fraction copy1(frac); // ���� ������ --> ������԰� ���򰥷��� ��������
	Fraction copy2 = frac; // ���� ������ --> ����� ���ÿ� �ʱ�ȭ�ϴ� ���� ��������� �ƴ�
	copy2 = frac; // ���� ���� ������

	CreateFraction();

	return 0;
}