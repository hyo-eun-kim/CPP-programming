#include <iostream>
using namespace std;

typedef struct Point {
	int xpos;
	int ypos;
} Point;

// ����ü�� ������� �� ���� ���� ����ϴ� �Լ��� ������ ���·� �����ϰ�
// ������ �� ���� �����Ͽ� �� �Լ��� �̿��� ���������� �����ϴ� main �Լ��� �����غ���
// �� ����ü Point ���� ������ ������ ������ new �����ڸ� �̿��ؼ� �����ؾ� �ϸ�
// �Ҵ�� �޸� ������ �Ҹ굵 ö���ؾ� �Ѵ�.

// Pointer& PntAdder(const Point &p1, const Point &p2)

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* p = new Point;
	p->xpos = p1.xpos + p2.xpos;
	p->ypos = p1.ypos + p2.ypos;
	return *p;
}


int main(void) {

	Point* p1 = new Point;
	p1->xpos = 2;
	p1->ypos = 3;

	Point* p2 = new Point;
	p2->xpos = 4;
	p2->ypos = 2;

	Point& p = PntAdder(*p1, *p2);

	cout << p.xpos << endl;
	cout << p.ypos << endl;


	delete p1;
	delete p2;
	delete &p;

	return 0;
}