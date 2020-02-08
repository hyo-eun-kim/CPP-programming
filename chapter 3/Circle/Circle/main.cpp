#include <iostream>
using namespace std;

// 캡슐화를 이용한 예제

class Point {
private:
	int xpos;
	int ypos;
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}

	void ShowPointInfo() const{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	} 
};

// 원의 중심정보와 반지름의 길이정보를 저장 출력할 수 있어야 한다.
class Circle {
private:
	Point center;
	int r;
public:
	void Init(int x, int y, int radius) {
		center.Init(x, y);
		r = radius;
	}
	void ShowCircleInfo() const {
		cout << "radius: " << r << endl;
		center.ShowPointInfo();
	}
};


class Ring {
private:
	Circle inner_circle;
	Circle outer_circle;
public:
	void Init(int inner_x, int inner_y, int inner_r, int outer_x, int outer_y, int outer_r) {
		inner_circle.Init(inner_x, inner_y, inner_r);
		outer_circle.Init(outer_x, outer_y, outer_r);
	}
	void ShowRingInfo() {
		cout << "Inner Circle Info..." << endl;
		inner_circle.ShowCircleInfo();
		cout << endl;

		cout << "Outer Circle Info..." << endl;
		outer_circle.ShowCircleInfo();
		cout << endl;
	}
};
// 두 개의 원(안쪽 원, 바깥쪽 원)으로 표현가능


int main(void) {

	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}