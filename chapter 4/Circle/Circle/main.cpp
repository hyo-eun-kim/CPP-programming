#include <iostream>
using namespace std;

// ĸ��ȭ�� �̿��� ����

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

// ���� �߽������� �������� ���������� ���� ����� �� �־�� �Ѵ�.
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
// �� ���� ��(���� ��, �ٱ��� ��)���� ǥ������


int main(void) {

	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}