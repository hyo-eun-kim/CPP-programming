#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend ostream& operator<<(ostream& os, const Point& p);
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {};

	Point operator+(const Point& p) const{
		
		return Point (xpos + p.xpos, ypos + p.ypos);
	}
};

ostream& operator<<(ostream& os, const Point& p) {

	os << "[" << p.xpos << "," << p.ypos << "]" << endl;
	return os;
}

class Adder {
public:
	Adder() {};

	int operator()(const int& n1, const int& n2) {
		return n1 + n2;
	}

	double operator()(double& n1,double& n2) {
		return n1 + n2;
	}

	Point operator()(const Point& p1, const Point& p2) {
		return p1 + p2;
	}
};


int main(void) {

	Adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.7) << endl;
	cout << adder(Point(3, 4), Point(7, 9));
	return 0;
}