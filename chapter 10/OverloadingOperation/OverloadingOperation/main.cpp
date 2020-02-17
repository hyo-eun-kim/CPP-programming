#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
public:
	Point(int n1=0, int n2=0)
		:num1(n1), num2(n2){}
	void ShwPoint() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}

	// 멤버함수에 의한 연산자 오버로딩
	Point operator+(const Point& point) {
		Point ret(num1 + point.num1, num2 + point.num2);
		return ret;
	}
};

int main(void) {

	Point pos1(3, 4);
	Point pos2(10, 20);
	
	// 아래 두 줄이 하는 일은 완벽히 동일
	Point pos3 = pos1.operator+(pos2);
	Point pos4 = pos1 + pos2;

	pos3.ShwPoint();
	pos4.ShwPoint();

	return 0;
}