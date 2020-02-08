#include "Point.h"
#include "Rectangle.h"

int main(void) {

	Point p1;
	if (!p1.Init(-2, 4)) {
		cout << "�ʱ�ȭ ����" << endl;
	}
	if (!p1.Init(2, 4)) {
		cout << "�ʱ�ȭ ����" << endl;
	}

	Point p2;
	if (!p2.Init(5, 2)) {
		cout << "�ʱ�ȭ ����" << endl;
	}

	Rectangle rec;
	if (!rec.Init(p2, p1)) {
		cout << "���簢�� �ʱ�ȭ ����" << endl;
	}

	if (!rec.Init(p1, p2)) {
		cout << "���簢�� �ʱ�ȭ ����" << endl;
	}

	rec.ShowRecInfo();
	return 0;
}