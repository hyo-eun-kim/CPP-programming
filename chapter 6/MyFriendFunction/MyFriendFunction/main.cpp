#include <iostream>
using namespace std;

class Point;

class PointOP {
private:
	int opcnt;
public:
	PointOP() {
		opcnt = 0;
	}
	Point PointAdd(const Point& pnt1, const Point& pnt2);
	Point PointSub(const Point& pnt1, const Point& pnt2);
	~PointOP(){
		cout << "Operation time: " << opcnt << endl;
	}
};

class Point {
private:
	int x;
	int y;
	friend class PointOP;
public:
	Point(const int& xpos, const int& ypos)
		:x(xpos), y(ypos) {};
	friend Point PointOP::PointAdd(const Point&, const Point&); 
	// PointOP Ŭ������ PointAdd �Լ��� Point Ŭ������ ģ�� -> Point Ŭ������ ��������� ���� ����
	friend Point PointOP::PointSub(const Point&, const Point&);
	// PointOP Ŭ������ PointSub �Լ��� Point Ŭ������ ģ�� -> Point Ŭ������ ��������� ���� ����
	friend void ShowPointPos(const Point& pnt);
	// ShowPointPos �Լ��� Point Ŭ������ ģ�� -> Point Ŭ������ ��������� ���� ����

};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}
Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

void ShowPointPos(const Point& pnt) {
	cout << "x: " << pnt.x << endl;
	cout << "y: " << pnt.y << endl;
}

int main(void) {

	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));
	return 0;
}