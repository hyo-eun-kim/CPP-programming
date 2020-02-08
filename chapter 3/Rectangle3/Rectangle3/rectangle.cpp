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
		cout << "�߸��� ��ġ���� ����" << endl;
		return false;
	}
}


void Rectangle::ShowRecInfo() const {
	cout << "�� ���: " << "[" << upLeft.GetX() << ", " << upLeft.GetY() << "]" << endl;
	cout << "�� �ϴ�: " << "[" << lowRight.GetX() << ", " << lowRight.GetY() << "]" << endl;
}