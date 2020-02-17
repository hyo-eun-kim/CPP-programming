#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend const Point& operator++(Point& p, int);
public:
	Point(int x=0, int y=0)
		:xpos(x), ypos(y){}
	void ShowPoint() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	// 전위증가연산자 오버로딩
	Point& operator++() {
		xpos++;
		ypos++;
		return *this;
	}

	// 전위감소연산자 오버로딩
	Point& operator--() {
		xpos--;
		ypos--;
		return *this;
	}

	// 후위감소연산자 (단항연산자!)
	const Point& operator--(int) {
		const Point ret = *this;
		xpos--;
		ypos--;
		return ret;
	}

};

// 후위증가연산자
const Point& operator++(Point& p, int) {
	const Point ret = p;
	p.xpos++;
	p.ypos++;
	return ret;
}

int main(void) {

	Point pos(3, 5);
	Point cpy;
	cpy = pos--; // pos.operator--(int) 호출
	pos.ShowPoint(); 	// pos : [2, 4]
	cpy.ShowPoint();	// cpy : [3, 5]

	cpy = pos++; // operator++(pos, int) 호출
	cpy.ShowPoint();	// cpy : [2, 4]
	pos.ShowPoint();	// pos : [3, 5]

	return 0;
}