#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
	// 전역함수를 통해 클래스의 private 멤버변수에 접근하기 위해 friend 선언을 해주었다.
	friend Point& operator+(Point& p1, Point& p2);
public:
	Point(int n1 = 0, int n2 = 0)
		:num1(n1), num2(n2) {}
	void ShwPoint() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}

};

// 전역함수를 이용한 연산자 오버로딩
// *오버로딩? 함수의 이름은 동일하지만 인자의 수, 인자의 자료형, const 선언유무가 다른 경우 
// 함수가 오버로딩 되었다고 이야기함
Point& operator+(Point& p1, Point& p2) {
	Point ret(p1.num1 + p2.num1, p1.num2 + p2.num2);
	return ret;
}

int main(void) {

	Point pos1(3, 4);
	Point pos2(10, 20);

	// 전역함수로 정의된 + 연산자 오버로딩 함수가 호출됨
	// 전역함수로 정의된 연산자 오버로딩 함수와 지역변수로 선언된 함수가 있다면
	// 전역함수는 지역함수에 의해 가려진다.

	Point pos3 = pos1 + pos2; // pos1, pos2를 전역함수 operator+의 인자로 전달함

	pos3.ShwPoint();


	return 0;
}