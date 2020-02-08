#include <iostream>
using namespace std;

class Point {
public:
	int x;
	int y;
};

class Rectangle {
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRectangle();
};

void Rectangle::ShowRectangle() {
	cout << "좌 상단: " << "[" << upLeft.x << ", " << upLeft.y << "]" << endl;
	cout << "우 하단: " << "[" << lowRight.x << ", " << lowRight.y << "]" << endl;
}

int main(void) {

	// 1. 우리는 좌표값을 0과 100 사이로 제한하고 싶었으나 방지하지 못함
	// 2. 좌상단의 x좌표보다 우하단의 x좌표가 더 커야하는 데 방지하지 못함
	// -> 여기서 이 문제점이 발생하고 있다.

	// 우리는 제한된 방법으로의 접근만 허용하여 잘못된 값이 저장되지 않도록 해야 한다.
	// 또한 실수를 했을 때 실수가 발견될 수 있도록 코드를 수정해야 한다.

	Point p1 = { 5, 9 };
	Point p2 = { -2, 4 };
	Rectangle rec = { p1, p2 };
	rec.ShowRectangle();
	

	return 0;
}