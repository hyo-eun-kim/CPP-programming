#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend ostream& operator<<(ostream& os, Point& p);

public:
	Point(int x=0, int y=0)
		:xpos(x), ypos(y){}
};


ostream& operator<<(ostream& os, Point& p) {
	os << "[" << p.xpos << ", " << p.ypos << "]" << endl;
	return os;
}

int main(void) {

	Point p1(1, 3);
	Point p2(101, 303);

	cout << p1; 
	cout << p2;
	cout << "----------------------" << endl;

	cout << p1 << p2;
	return 0;
}