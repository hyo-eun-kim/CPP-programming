#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(const int xpos, const int ypos) {
	x = xpos;
	y = ypos;
}
int Point::GetX() const {
	return x;
}
int Point::GetY() const {
	return y;
}
bool Point::SetX(int xpos) {
	if (0 <= xpos && xpos <= 100) {
		x = xpos;
		return true;
	}
	else {
		cout << "¹üÀ§ ÀÌÅ»" << endl;
		return false;
	}
}
bool Point::SetY(int ypos) {
	if (0 <= ypos && ypos <= 100) {
		y = ypos;
		return true;
	}
	else {
		cout << "¹üÀ§ ÀÌÅ»" << endl;
		return false;
	}
}