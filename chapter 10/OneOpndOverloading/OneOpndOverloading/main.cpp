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

	// 멤버함수로 정의한 연산자 오버로딩
	Point& operator++() {
		xpos++;
		ypos++;
		return *this;
	}

	// 멤버함수로 정의한 연산자 오버로딩
	Point& operator--() {
		xpos--;
		ypos--;
		return *this;
	}
};

int main(void) {

	Point pos(1, 2);

	++pos; // pos1.operator++() 호출
	pos.ShowPosition(); // [2, 3]

	--pos; // pos.operator--() 호출
	pos.ShowPosition(); // [1, 2]

	++(++pos); // 자기자신을 참조할 수 있는 reference를 반환하기 때문에 가능한 코드!
	pos.ShowPosition(); // [3, 4]

	--(--pos);
	pos.ShowPosition(); // [1, 2]

}