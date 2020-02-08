#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

class Rectangle {
private:
	Point upLeft;
	Point lowRight;
public:
	bool Init(const Point& p1, const Point& p2);
	void ShowRecInfo() const;
};
