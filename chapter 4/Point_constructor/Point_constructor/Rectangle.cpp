#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(int x1, int y1, int x2, int y2) :upLeft(x1, y1), lowRight(x2, y2) {

}
void Rectangle::Show() const {
	cout << "upLeft" << endl;
	cout << upLeft.GetX() << ", " << upLeft.GetY() << endl;
	cout << endl;

	cout << "lowRight" << endl;
	cout << lowRight.GetX() << ", " << lowRight.GetY() << endl;
	cout << endl;
}