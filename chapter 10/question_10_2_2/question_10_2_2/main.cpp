#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend Point& operator~(const Point& p);
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {}

	void ShowPosition() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

};


// Q2.
// ~ �����ڴ� ���� �����ڷμ� ��Ʈ���� not�� �ǹ̸� ���´�.
// �� ~ �����ڴ� ��Ʈ������ 1�� 0����, 0�� 1���� �ٲ۴�.
// �̿� �츮�� Point ��ü�� ������� ������ ���� ������ �����ϵ��� ~ �����ڸ� �����ε��ϰ��� �Ѵ�.
// Point pos2 = ~pos1; 
// ���� ~ ������ ����� ��ȯ�� ��ü�� xpos�� ������� pos1�� ypos����
// ��ȯ�� ��ü�� ypos ������� pos1�� xpos ���� ����Ǿ�� �Ѵ�.

Point& operator~(const Point& p) {
	Point ret(p.ypos, p.xpos);
	return ret;
}

int main(void) {

	Point pos(1, 2);
	Point pos2 = ~pos; // operator~(pos)�� ȣ��
	Point pos3 = ~pos2; // operator~(pos2)�� ȣ��

	pos.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	return 0;
}