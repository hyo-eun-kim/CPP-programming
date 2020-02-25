#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend ostream& operator<<(ostream& os, Point& point);
public:
	Point(int x=0, int y=0) :xpos(x), ypos(y) {};

};

ostream& operator<<(ostream& os, Point& point) {
	os << "[" << point.xpos << ", " << point.ypos << "]" << endl;
	return os;
}

class BoundCheckPointArray {
private:
	int len;
	Point* arr;
public:
	BoundCheckPointArray(int len) :len(len) {
		arr = new Point[len];
	}

	Point& operator[](int index) {
		if (index < 0 || index >= len) {
			cout << "out of index" << endl;
		}
		else {
			return arr[index];
		}
	}

	Point& operator[](int index) const{
		if (index < 0 || index >= len) {
			cout << "out of index" << endl;
		}
		else {
			return arr[index];
		}
	}

	int GetArrLen() const {
		return len;
	}

	~BoundCheckPointArray() {
		delete arr;
	}
};

int main(void) {

	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++) {
		cout << arr[i];
	}
}