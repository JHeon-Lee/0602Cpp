#include <iostream>

using namespace std;

// �̵� ������

class Test
{
public:
	Test() = default;

	Test(const Test& t)
	{}

	Test(const Test&& t) // �̵� ������ --> R-Value�� ����ؼ� ����� ���� �����
	{}

	Test& operator = (const Test&& t) // �̵� ���� ������
	{}
};

int main()
{
	Test t;
	Test t2(t);

	Test t3(std::move(t)); // �̵� �����ڶ� ���� ����ؾ���

	t2 = std::move(t); // ���������� ��� �ؾ���

	return 0;
}

// ��� �����ڴ� ������ �˾ƾ��ϰ�, new, delete �� �ٸ� �����ڵ��� ������ ��� �Ǵ��� �˾Ƶ־���
// ����Ʈ �����ʹ� ��ȭ ������ ���� ������

// homework Ǯ�� - list : �迭�� ���, ��/���� ������ ��ŷ��, ����/������ ����� �Ͼ��, ���������� ����Ҷ� ���� 