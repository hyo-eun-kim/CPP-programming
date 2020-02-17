#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
	friend Point& operator-(Point& p1, Point& p2);
public:
	Point(int n1=0, int n2=0):
		num1(n1), num2(n2){}
	void ShowPoint() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}
};

Point& operator-(Point& p1, Point& p2) {
	Point ret(p1.num1 - p2.num1, p1.num2 - p2.num2);
	return ret;
}

// Q1.
// �����Լ� ������� - ������ �����ε�
// ��� �� - ������ ����� ���� Point ��ü ��ȯ

int main(void) {
	Point p1(1, 2);
	Point p2(5, 3);

	Point p1_minus_p2 = p2 - p1;
	p1_minus_p2.ShowPoint(); // [4, 1]

	return 0;

}