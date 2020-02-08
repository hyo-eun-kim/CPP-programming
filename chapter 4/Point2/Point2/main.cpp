#include <iostream>
using namespace std;

// 1. Ä¸½¶È­
// 2. ¸â¹ö ÀÌ´Ï¼È¶óÀÌÀú
// 3. »ı¼ºÀÚ (constructor)

class Point {
private:
	int x;
	int y;
public:
	Point(int xpos, int ypos)
		:x(xpos), y(ypos) {
	}
	
	void Show() {
		cout << "[" << x << ", " << y << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int r;
public:
	Circle(int x, int y, int radius)
		:center(x, y), r(radius) {};
	void Show() {
		cout << "radius: " << r << endl;
		center.Show();
	}
};

class Ring {
private:
	Circle inner;
	Circle outer;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2)
		:inner(x1, y1, r1), outer(x2, y2, r2) {};
	void Show() {
		cout << "Inner Circle" << endl;
		inner.Show();

		cout << "Outer Circle" << endl;
		outer.Show();
	}
};

int main(void) {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.Show();
	return 0;
}