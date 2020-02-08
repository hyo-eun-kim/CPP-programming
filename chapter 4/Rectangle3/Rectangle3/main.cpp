#include "Point.h"
#include "Rectangle.h"

int main(void) {

	Point p1;
	if (!p1.Init(-2, 4)) {
		cout << "초기화 실패" << endl;
	}
	if (!p1.Init(2, 4)) {
		cout << "초기화 실패" << endl;
	}

	Point p2;
	if (!p2.Init(5, 2)) {
		cout << "초기화 실패" << endl;
	}

	Rectangle rec;
	if (!rec.Init(p2, p1)) {
		cout << "직사각형 초기화 실패" << endl;
	}

	if (!rec.Init(p1, p2)) {
		cout << "직사각형 초기화 실패" << endl;
	}

	rec.ShowRecInfo();
	return 0;
}