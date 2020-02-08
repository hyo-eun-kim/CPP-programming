#include <iostream>
#include "Point.h"
using namespace std;

bool Point::Init(int xpos, int ypos) {
	if ((0 <= xpos && xpos <= 100) && (0 <= ypos && ypos <= 100)) {
		x = xpos;
		y = ypos;
		return true;
	}
	else {
		cout << "¹üÀ§¸¦ ¹þ¾î³µ½À´Ï´Ù." << endl;
		return false;
	}
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
		cout << "x°¡ ¹üÀ§¸¦ ¹þ¾î³µ½À´Ï´Ù." << endl;
		return false;
	}
}

bool Point::SetY(int ypos) {
	if (0 <= ypos && ypos <= 100) {
		y = ypos;
		return true;
	}
	else {
		cout << "y°¡ ¹üÀ§¸¦ ¹þ¾î³µ½À´Ï´Ù." << endl;
		return false;
	}
}