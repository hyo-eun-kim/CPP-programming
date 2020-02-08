#pragma once
#include "Point.h"

class Rectangle {
private:
	Point upLeft;
	Point lowRight;
public:
	Rectangle(int x1, int y1, int x2, int y2);
	void Show() const;
};