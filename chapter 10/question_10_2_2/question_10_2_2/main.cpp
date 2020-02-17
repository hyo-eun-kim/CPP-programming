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
// ~ 연산자는 단항 연산자로서 비트단위 not의 의미를 갖는다.
// 즉 ~ 연산자는 비트단위로 1은 0으로, 0은 1으로 바꾼다.
// 이에 우리는 Point 객체를 대상으로 다음과 같이 연산이 가능하도록 ~ 연산자를 오버로딩하고자 한다.
// Point pos2 = ~pos1; 
// 위의 ~ 연산의 결과로 반환된 객체의 xpos의 멤버에는 pos1의 ypos값이
// 반환된 객체의 ypos 멤버에는 pos1의 xpos 값이 저장되어야 한다.

Point& operator~(const Point& p) {
	Point ret(p.ypos, p.xpos);
	return ret;
}

int main(void) {

	Point pos(1, 2);
	Point pos2 = ~pos; // operator~(pos)가 호출
	Point pos3 = ~pos2; // operator~(pos2)가 호출

	pos.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	return 0;
}