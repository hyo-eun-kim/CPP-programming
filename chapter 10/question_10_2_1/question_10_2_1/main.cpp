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
	// 부호연산자로서 '-'는 단항연산자이다.
	// 이 연산자는 피연산자의 부호를 반전시킨 결과과를 반환한다.
	// Point pos2 = -pos1 하면 pos1의 멤버변수는 그대로, 
	// pos2에는 pos1의 각각의 멤버변수가 부호 반전된 형태로 멤버변수를 갖도록
	Point operator-() {
		Point ret(-xpos, -ypos);
		return ret;
	}
};

int main(void) {

	Point pos(1, 2);
	Point pos2 = -pos; // pos.operator-()가 호출
	Point pos3 = -pos2; // pos2.operator-()가 호출

	pos.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	return 0;
}