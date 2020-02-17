#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {}
	void ShowPoint() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	// 서로 다른 자료형끼리의 연산을 가능하게 해줌
	Point operator*(int n) {
		Point ret(xpos * n, ypos * n);
		return ret;
	}

};


int main(void) {

	Point pos(1, 2);
	Point cpy;

	cpy = pos * 2;
	cpy.ShowPoint(); // [2, 4]
	pos.ShowPoint(); // [1, 2]

	cpy = pos * 2 * 3;
	cpy.ShowPoint(); // [6, 12]
	pos.ShowPoint(); // [1, 2]

	// pos * 2 의 연산은 사실상 pos.operator*(2)를 수행한 것과 동일하다.
	// 하지만 곱셈의 경우 교환법칙이 성립하듯이
	// 2 * pos 의 연산도 가능하게 하고싶다!
	// 하지만 멤버함수로 연산자 오버로딩을 정의하면 이것이 불가능하다 :(
	// 따라서 우리는 전역함수로 연산자 오버로딩을 정의하여 교환법칙을 성립하도록 해보고자 한다!

	return 0;
}