#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {}
	void ShowPoint() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	// ���� �ٸ� �ڷ��������� ������ �����ϰ� ����
	Point operator*(int n) {
		Point ret(xpos * n, ypos * n);
		return ret;
	}

};


int main(void) {

	Point pos(1, 2);
	Point cpy;

	cpy = pos * 2;
	cpy.ShowPoint(); // [2, 4]
	pos.ShowPoint(); // [1, 2]

	cpy = pos * 2 * 3;
	cpy.ShowPoint(); // [6, 12]
	pos.ShowPoint(); // [1, 2]

	// pos * 2 �� ������ ��ǻ� pos.operator*(2)�� ������ �Ͱ� �����ϴ�.
	// ������ ������ ��� ��ȯ��Ģ�� �����ϵ���
	// 2 * pos �� ���굵 �����ϰ� �ϰ�ʹ�!
	// ������ ����Լ��� ������ �����ε��� �����ϸ� �̰��� �Ұ����ϴ� :(
	// ���� �츮�� �����Լ��� ������ �����ε��� �����Ͽ� ��ȯ��Ģ�� �����ϵ��� �غ����� �Ѵ�!

	return 0;
}