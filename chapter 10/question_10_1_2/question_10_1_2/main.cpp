#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
	
public:
	Point(int n1 = 0, int n2 = 0) :
		num1(n1), num2(n2) {}
	void ShowPoint() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}

	// 멤버함수로 += 연산자 오버로딩
	Point& operator+=(Point& p) {
		num1 += p.num1;
		num2 += p.num2;
		return *this;
	}

	// 멤버함수로 -= 연산자 오버로딩
	Point& operator-=(Point& p) {
		num1 -= p.num1;
		num2 -= p.num2;
		return *this;
	}
};

// Q2.
// 멤버함수 기반으로 +=, -= 연산자 오버로딩
// pos1+=pos2의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값 만큼 멤버 별 증가
// pos1-=pos2의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값 만큼 멤버 별 감소
// 연산의 결과로 값이 증가 및 감소한 pos1 객체를 반환하도록 (이왕이면 참조형으로 반환)

int main(void) {
	Point p1(1, 2);
	Point p2(5, 3);

	Point& p = p1 += p2;
	p.ShowPoint();	// [6, 5]
	p1.ShowPoint(); // [6, 5]
	p2.ShowPoint(); // [5, 3]

	cout << "------------------------------" << endl;

	Point& q = p2 -= p1;
	q.ShowPoint();	// [-1, -2]
	p1.ShowPoint(); // [6, 5]
	p2.ShowPoint(); // [-1, -2]

	return 0;
}