#include <iostream>

using namespace std;

// 이동 생성자

class Test
{
public:
	Test() = default;

	Test(const Test& t)
	{}

	Test(const Test&& t) // 이동 생성자 --> R-Value를 사용해서 사용한 값은 사라짐
	{}

	Test& operator = (const Test&& t) // 이동 대입 연산자
	{}
};

int main()
{
	Test t;
	Test t2(t);

	Test t3(std::move(t)); // 이동 생성자란 것을 명시해야함

	t2 = std::move(t); // 마찬가지로 명시 해야함

	return 0;
}

// 산술 연산자는 만들줄 알아야하고, new, delete 등 다른 연산자들은 구현이 어떻게 되는지 알아둬야함
// 스마트 포인터는 심화 면접에 가끔 출제됨

// homework 풀이 - list : 배열과 비슷, 앞/뒤의 정보가 링킹됨, 삽입/삭제가 빈번히 일어날때, 순차적으로 사용할때 용이 