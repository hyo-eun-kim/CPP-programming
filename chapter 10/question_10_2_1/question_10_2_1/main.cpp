#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {}

	void ShowPosition() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}


	// Q1.
	// ��ȣ�����ڷμ� '-'�� ���׿������̴�.
	// �� �����ڴ� �ǿ������� ��ȣ�� ������Ų ������� ��ȯ�Ѵ�.
	// Point pos2 = -pos1 �ϸ� pos1�� ��������� �״��, 
	// pos2���� pos1�� ������ ��������� ��ȣ ������ ���·� ��������� ������
	Point operator-() {
		Point ret(-xpos, -ypos);
		return ret;
	}
};

int main(void) {

	Point pos(1, 2);
	Point pos2 = -pos; // pos.operator-()�� ȣ��
	Point pos3 = -pos2; // pos2.operator-()�� ȣ��

	pos.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	return 0;
}