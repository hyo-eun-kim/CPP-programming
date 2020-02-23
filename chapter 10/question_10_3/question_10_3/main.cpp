#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend istream& operator>>(istream& is, Point& p);
	friend ostream& operator<<(ostream& os, Point& p);
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y){}

};

// Point 클래스의 private 멤버함수에 접근하기 위해
// Point 클래스에서 함수를 friend 선언해주었다.
istream& operator>>(istream& is, Point& p) {
	cout << "x, y 좌표 순으로 입력: ";
	is >> p.xpos;
	is >> p.ypos;
	return is;
}

ostream& operator<<(ostream& os, Point& p) {
	os << "[" << p.xpos << ", " << p.ypos << "]" << endl;
	fflush(stdout);
	return os;
}

int main(void) {

	Point pos1;
	cin >> pos1;	// operator>>(cin, pos1)
	cout << pos1;	// operator<<(cout, pos1)

	Point pos2;
	cin >> pos2;	// operator>>(cin, pos2)
	cout << pos2;	// operator<<(cout, pos2)

	return 0;
}