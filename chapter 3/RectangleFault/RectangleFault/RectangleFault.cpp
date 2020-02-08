#include <iostream>
using namespace std;

class Point {
public:
	int x;
	int y;
};

class Rectangle {
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRectangle();
};

void Rectangle::ShowRectangle() {
	cout << "�� ���: " << "[" << upLeft.x << ", " << upLeft.y << "]" << endl;
	cout << "�� �ϴ�: " << "[" << lowRight.x << ", " << lowRight.y << "]" << endl;
}

int main(void) {

	// 1. �츮�� ��ǥ���� 0�� 100 ���̷� �����ϰ� �;����� �������� ����
	// 2. �»���� x��ǥ���� ���ϴ��� x��ǥ�� �� Ŀ���ϴ� �� �������� ����
	// -> ���⼭ �� �������� �߻��ϰ� �ִ�.

	// �츮�� ���ѵ� ��������� ���ٸ� ����Ͽ� �߸��� ���� ������� �ʵ��� �ؾ� �Ѵ�.
	// ���� �Ǽ��� ���� �� �Ǽ��� �߰ߵ� �� �ֵ��� �ڵ带 �����ؾ� �Ѵ�.

	Point p1 = { 5, 9 };
	Point p2 = { -2, 4 };
	Rectangle rec = { p1, p2 };
	rec.ShowRectangle();
	

	return 0;
}