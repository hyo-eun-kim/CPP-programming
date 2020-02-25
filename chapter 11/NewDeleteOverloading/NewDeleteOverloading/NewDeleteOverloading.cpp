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
		void* adr = new char[size]; // ���ڷ� ���� ������ŭ �޸� �Ҵ�
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
	Point* prt = new Point(3, 4); // �츮�� ������ new ������ ȣ��
	cout << *prt;
	delete prt; // �츮�� ������ delete ȣ��

	return 0;
}