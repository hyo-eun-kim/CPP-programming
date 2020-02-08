#include <iostream>
#include "Rectangle.h"
#include "Point.h"
using namespace std;

bool Rectangle::Init(const Point& p1, const Point& p2) {
	if ((p1.GetX() < p2.GetX()) && (p1.GetY() > p2.GetY())) {
		upLeft = p1;
		lowRight = p2;
		return true;
	}
	else {
		cout << "잘못된 위치정보 전달" << endl;
		return false;
	}
}


void Rectangle::ShowRecInfo() const {
	cout << "좌 상단: " << "[" << upLeft.GetX() << ", " << upLeft.GetY() << "]" << endl;
	cout << "우 하단: " << "[" << lowRight.GetX() << ", " << lowRight.GetY() << "]" << endl;
}