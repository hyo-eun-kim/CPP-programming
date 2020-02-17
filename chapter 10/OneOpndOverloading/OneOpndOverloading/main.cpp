#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y){}

	void ShowPosition() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	// ����Լ��� ������ ������ �����ε�
	Point& operator++() {
		xpos++;
		ypos++;
		return *this;
	}

	// ����Լ��� ������ ������ �����ε�
	Point& operator--() {
		xpos--;
		ypos--;
		return *this;
	}
};

int main(void) {

	Point pos(1, 2);

	++pos; // pos1.operator++() ȣ��
	pos.ShowPosition(); // [2, 3]

	--pos; // pos.operator--() ȣ��
	pos.ShowPosition(); // [1, 2]

	++(++pos); // �ڱ��ڽ��� ������ �� �ִ� reference�� ��ȯ�ϱ� ������ ������ �ڵ�!
	pos.ShowPosition(); // [3, 4]

	--(--pos);
	pos.ShowPosition(); // [1, 2]

}