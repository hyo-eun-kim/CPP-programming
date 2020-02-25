#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
	friend ostream& operator<<(ostream& os, Point& point);
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {};

	void* operator new(size_t size) {
		cout << "operator new: " << size << endl;
		void* adr = new char[size]; // 인자로 받은 공간만큼 메모리 할당
		return adr;
	}

	void operator delete(void* adr) {
		cout << "operator delete" << endl;
		delete[] adr;
	}
};

ostream& operator<<(ostream& os, Point& point) {
	os << "[" << point.xpos << ", " << point.ypos << "]" << endl;
	return os;
}

int main(void) {
	Point* prt = new Point(3, 4); // 우리가 정의한 new 연산자 호출
	cout << *prt;
	delete prt; // 우리가 정의한 delete 호출

	return 0;
}