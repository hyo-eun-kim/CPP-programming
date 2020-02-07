#include <iostream>
using namespace std;

typedef struct Point {
	int xpos;
	int ypos;
} Point;

// 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의하고
// 임의의 두 점을 선언하여 위 함수를 이용한 덧셈연산을 진행하는 main 함수를 정의해보자
// 단 구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행해야 하며
// 할당된 메모리 공간의 소멸도 철저해야 한다.

// Pointer& PntAdder(const Point &p1, const Point &p2)

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* p = new Point;
	p->xpos = p1.xpos + p2.xpos;
	p->ypos = p1.ypos + p2.ypos;
	return *p;
}


int main(void) {

	Point* p1 = new Point;
	p1->xpos = 2;
	p1->ypos = 3;

	Point* p2 = new Point;
	p2->xpos = 4;
	p2->ypos = 2;

	Point& p = PntAdder(*p1, *p2);

	cout << p.xpos << endl;
	cout << p.ypos << endl;


	delete p1;
	delete p2;
	delete &p;

	return 0;
}