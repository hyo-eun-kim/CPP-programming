#include <iostream>
using namespace std;


// ��������� private�� �����ϰ�
// ��������� �����ϴ� �Լ��� ������ �����Ͽ�
// ������ ���·� ��������� ������ ����ϴ� ���� "��������"�̴�.
// �̰��� ���� Ŭ������ �Ǳ� ���� �⺻������ �ȴ�.

class Point {
private:
	int x;
	int y;
public:
	bool InitMembers(int xpos, int ypos) {
		if ((0<= xpos && xpos<=100) && (0<=ypos && ypos<=100)) {
			x = xpos;
			y = ypos;
			return true;
		}
		else {
			cout << "������ ������ϴ�." << endl;
			return false;
		}

	}
	int GetX() const {
		return x;
	}
	int GetY() const {
		return y;
	}
	bool SetX(int xpos) {
		if (xpos < 0 || xpos>100) {
			cout << "X�� ������ ������ϴ�." << endl;
			return false;
		}
		else {
			x = xpos;
			return true;
		}
			
	}
	bool SetY(int ypos) {
		if (ypos < 0 || ypos>100) {
			cout << "Y�� ������ ������ϴ�." << endl;
			return false;
		}
		else {
			y = ypos;
			return true;
		}
	}
};

int main(void) {

	Point p1;
	p1.InitMembers(4, 5);
	cout << p1.GetX() << endl; // 4
	cout << p1.GetY() << endl; // 5

	Point p2;
	p2.SetX(-3); // X�� ������ ������ϴ�.
	cout << p2.GetX() << endl; // �����Ⱚ

	return 0;
}