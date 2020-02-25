#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend ostream& operator<<(ostream& os, Point_ptr pointer);
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {};

};

typedef Point* Point_ptr;


class BoundCheckPointArray {
private:
	int len;
	Point_ptr* arr;
public:
	BoundCheckPointArray(int len) :len(len) {
		arr = new Point_ptr[len];
	}

	// 값을 저장하는 데
	Point_ptr& operator[](int index) {
		cout << "Point_ptr& operator[](int index)" << endl;
		if (index < 0 || index >= len) {
			cout << "out of index" << endl;
		}
		else {
			return arr[index];
		}
	}

	// 값을 불러오는 데
	Point_ptr operator[](int index) const{
		cout << "const Point& operator[](int index) const" << endl;
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

ostream& operator<<(ostream& os, Point_ptr pointer) {
	os << "[" << (*pointer).xpos << ", " << (*pointer).ypos << "]" << endl;
}

int main(void) {

	BoundCheckPointArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	
	cout << "cout << arr 시작" << endl;
	for (int i = 0; i < arr.GetArrLen(); i++) {
		cout << arr[i];
	}


	for (int i = 0; i < arr.GetArrLen(); i++) {
		delete arr[i];
	}

	return 0;
}