#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
public:
	Point(int n1 = 0, int n2 = 0)
		:num1(n1), num2(n2) {}
	void ShowPosition() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}

	// 연산자 오버로딩
	Point operator+(const Point& obj) {
		Point point(num1 + obj.num1, num2 + obj.num2);
		return point;
	}
};

int main(void) {

	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2; // pos1.operator+(pos2) 가 실행되는 것

	pos1.ShowPosition(); // [3, 4]
	pos2.ShowPosition(); // [10, 20]
	pos3.ShowPosition(); // [13, 24]
	return 0;

}