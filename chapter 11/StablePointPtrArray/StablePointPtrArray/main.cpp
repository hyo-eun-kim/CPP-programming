#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend ostream& operator<<(ostream& os, Point& point);
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {};

};

ostream& operator<<(ostream& os, Point& point) {
	os << "[" << point.xpos << ", " << point.ypos << "]" << endl;
	return os;
}

typedef Point* Point_ptr;

class BoundCheckPointArray {
private:
	int len;
	Point_ptr* arr; 
public:
	BoundCheckPointArray(int len) :len(len) {
		arr = new Point_ptr[len];
	}

	Point_ptr& operator[](int index) {
		if (index < 0 || index >= len) {
			cout << "out of index" << endl;
		}
		else {
			return arr[index];
		}
	}

	Point_ptr& operator[](int index) const {
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
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++) {
		cout << *arr[i];
	}

	for (int i = 0; i < arr.GetArrLen(); i++) {
		delete arr[i];
	}

	return 0;
}