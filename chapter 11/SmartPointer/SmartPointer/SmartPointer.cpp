#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend ostream& operator<<(ostream& os, Point& point);
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {
		//cout << "Point 按眉 积己" << endl;
	};

	void Show() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}

	void* operator new(size_t size) {
		cout << "Point 按眉 积己" << endl;
		void* adr = new char[size];
		return adr;
	}

	~Point() {
		cout << "Point 按眉 家戈" << endl;
	}
};

ostream& operator<<(ostream& os, Point& point) {
	os << "[" << point.xpos << "," << point.ypos << "]" << endl;
	return os;
}


class SmarPtr {
private:
	Point* point;
public:
	SmarPtr(Point* pt) :point(pt) {};

	Point& operator*() {
		return *point;
	}

	Point* operator->() {
		return point;
	}

	~SmarPtr() {
		delete point;
	}
};


int main(void) {

	SmarPtr sptr1(new Point(1, 2));
	SmarPtr sptr2(new Point(2, 3));
	SmarPtr sptr3(new Point(4, 5));

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	return 0;
}