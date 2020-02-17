#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
	friend bool operator==(Point& p1, Point& p2);

public:
	Point(int n1 = 0, int n2 = 0) :
		num1(n1), num2(n2) {}
	void ShowPoint() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}
};

bool operator==(Point& p1, Point& p2) {

	if (p1.num1 == p2.num1 && p1.num2 == p2.num2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(Point& p1, Point& p2) {

	return !(p1 == p2);
}


// Q3.
// ==, != �����ڸ� �����ε� �غ���
// �� �� �����Լ��� ���·� �����ε�
// pos1==pos2 �� ����� ��� ����� ���� ���ٸ� true, �׷��� �ʴٸ� false ��ȯ
// pos1!=pos2 �� ����� ��� ����� ���� ���ٸ� false, �׷��� �ʴٸ� true ��ȯ
// ������ == �� ���� �����ε� �� ������ �̸� �̿��ϴ� ���·� != ������ �����ε�

int main(void) {

	Point p1(1, 2);
	Point p2(5, 3);
	
	cout << (p1 == p2) << endl; // false
	cout << (p1 != p2) << endl; // true

	Point p3(3, 3);
	Point p4(3, 3);

	cout << (p3 == p4) << endl; // true
	cout << (p3 != p4) << endl; // false

	return 0;
}