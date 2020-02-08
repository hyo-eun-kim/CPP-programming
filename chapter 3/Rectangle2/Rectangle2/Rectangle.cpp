#include <iostream>
using namespace std;


// 멤버변수를 private로 선언하고
// 멤버변수에 접근하는 함수를 별도로 정의하여
// 안전한 형태로 멤버변수의 접근을 허용하는 것이 "정보은닉"이다.
// 이것은 좋은 클래스가 되기 위한 기본조건이 된다.

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
			cout << "범위를 벗어났습니다." << endl;
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
			cout << "X가 범위를 벗어났습니다." << endl;
			return false;
		}
		else {
			x = xpos;
			return true;
		}
			
	}
	bool SetY(int ypos) {
		if (ypos < 0 || ypos>100) {
			cout << "Y가 범위를 벗어났습니다." << endl;
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
	p2.SetX(-3); // X가 범위를 벗어났습니다.
	cout << p2.GetX() << endl; // 쓰레기값

	return 0;
}