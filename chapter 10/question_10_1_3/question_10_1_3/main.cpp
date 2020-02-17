#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
	friend bool operator==(Point& p1, Point& p2);

public:
	Point(int n1 = 0, int n2 = 0) :
		num1(n1), num2(n2) {}
	void ShowPoint() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}
};

bool operator==(Point& p1, Point& p2) {

	if (p1.num1 == p2.num1 && p1.num2 == p2.num2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(Point& p1, Point& p2) {

	return !(p1 == p2);
}


// Q3.
// ==, != 연산자를 오버로딩 해보자
// 둘 다 전역함수의 형태로 오버로딩
// pos1==pos2 의 결과로 모든 멤버의 값이 값다면 true, 그렇지 않다면 false 반환
// pos1!=pos2 의 결과로 모든 멤버의 값이 값다면 false, 그렇지 않다면 true 반환
// 연산자 == 을 먼저 오버로딩 한 다음에 이를 이용하는 형태로 != 연산자 오버로딩

int main(void) {

	Point p1(1, 2);
	Point p2(5, 3);
	
	cout << (p1 == p2) << endl; // false
	cout << (p1 != p2) << endl; // true

	Point p3(3, 3);
	Point p4(3, 3);

	cout << (p3 == p4) << endl; // true
	cout << (p3 != p4) << endl; // false

	return 0;
}