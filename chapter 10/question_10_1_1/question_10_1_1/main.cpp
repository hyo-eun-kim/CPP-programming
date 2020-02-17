#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
	friend Point& operator-(Point& p1, Point& p2);
public:
	Point(int n1=0, int n2=0):
		num1(n1), num2(n2){}
	void ShowPoint() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}
};

Point& operator-(Point& p1, Point& p2) {
	Point ret(p1.num1 - p2.num1, p1.num2 - p2.num2);
	return ret;
}

// Q1.
// 전역함수 기반으로 - 연산자 오버로딩
// 멤버 별 - 연산의 결과를 담은 Point 객체 반환

int main(void) {
	Point p1(1, 2);
	Point p2(5, 3);

	Point p1_minus_p2 = p2 - p1;
	p1_minus_p2.ShowPoint(); // [4, 1]

	return 0;

}