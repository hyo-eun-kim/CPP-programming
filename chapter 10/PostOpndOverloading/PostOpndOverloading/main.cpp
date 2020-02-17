#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend const Point& operator++(Point& p, int);
public:
	Point(int x=0, int y=0)
		:xpos(x), ypos(y){}
	void ShowPoint() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	// �������������� �����ε�
	Point& operator++() {
		xpos++;
		ypos++;
		return *this;
	}

	// �������ҿ����� �����ε�
	Point& operator--() {
		xpos--;
		ypos--;
		return *this;
	}

	// �������ҿ����� (���׿�����!)
	const Point& operator--(int) {
		const Point ret = *this;
		xpos--;
		ypos--;
		return ret;
	}

};

// ��������������
const Point& operator++(Point& p, int) {
	const Point ret = p;
	p.xpos++;
	p.ypos++;
	return ret;
}

int main(void) {

	Point pos(3, 5);
	Point cpy;
	cpy = pos--; // pos.operator--(int) ȣ��
	pos.ShowPoint(); 	// pos : [2, 4]
	cpy.ShowPoint();	// cpy : [3, 5]

	cpy = pos++; // operator++(pos, int) ȣ��
	cpy.ShowPoint();	// cpy : [2, 4]
	pos.ShowPoint();	// pos : [3, 5]

	return 0;
}