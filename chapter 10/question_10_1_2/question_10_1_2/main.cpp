#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
	
public:
	Point(int n1 = 0, int n2 = 0) :
		num1(n1), num2(n2) {}
	void ShowPoint() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}

	// ����Լ��� += ������ �����ε�
	Point& operator+=(Point& p) {
		num1 += p.num1;
		num2 += p.num2;
		return *this;
	}

	// ����Լ��� -= ������ �����ε�
	Point& operator-=(Point& p) {
		num1 -= p.num1;
		num2 -= p.num2;
		return *this;
	}
};

// Q2.
// ����Լ� ������� +=, -= ������ �����ε�
// pos1+=pos2�� ����� pos1�� ������� ���� pos2�� ������� �� ��ŭ ��� �� ����
// pos1-=pos2�� ����� pos1�� ������� ���� pos2�� ������� �� ��ŭ ��� �� ����
// ������ ����� ���� ���� �� ������ pos1 ��ü�� ��ȯ�ϵ��� (�̿��̸� ���������� ��ȯ)

int main(void) {
	Point p1(1, 2);
	Point p2(5, 3);

	Point& p = p1 += p2;
	p.ShowPoint();	// [6, 5]
	p1.ShowPoint(); // [6, 5]
	p2.ShowPoint(); // [5, 3]

	cout << "------------------------------" << endl;

	Point& q = p2 -= p1;
	q.ShowPoint();	// [-1, -2]
	p1.ShowPoint(); // [6, 5]
	p2.ShowPoint(); // [-1, -2]

	return 0;
}