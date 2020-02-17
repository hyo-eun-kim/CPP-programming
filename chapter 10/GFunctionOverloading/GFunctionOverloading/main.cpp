#include <iostream>
using namespace std;

class Point {
private:
	int num1, num2;
	// �����Լ��� ���� Ŭ������ private ��������� �����ϱ� ���� friend ������ ���־���.
	friend Point& operator+(Point& p1, Point& p2);
public:
	Point(int n1 = 0, int n2 = 0)
		:num1(n1), num2(n2) {}
	void ShwPoint() {
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}

};

// �����Լ��� �̿��� ������ �����ε�
// *�����ε�? �Լ��� �̸��� ���������� ������ ��, ������ �ڷ���, const ���������� �ٸ� ��� 
// �Լ��� �����ε� �Ǿ��ٰ� �̾߱���
Point& operator+(Point& p1, Point& p2) {
	Point ret(p1.num1 + p2.num1, p1.num2 + p2.num2);
	return ret;
}

int main(void) {

	Point pos1(3, 4);
	Point pos2(10, 20);

	// �����Լ��� ���ǵ� + ������ �����ε� �Լ��� ȣ���
	// �����Լ��� ���ǵ� ������ �����ε� �Լ��� ���������� ����� �Լ��� �ִٸ�
	// �����Լ��� �����Լ��� ���� ��������.

	Point pos3 = pos1 + pos2; // pos1, pos2�� �����Լ� operator+�� ���ڷ� ������

	pos3.ShwPoint();


	return 0;
}