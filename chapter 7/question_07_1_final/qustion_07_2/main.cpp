#include <iostream>
using namespace std;

// 정사각형을 의미하는 Square 클래스
// 직사각형을 의미하는 Rectangle 클래스
// 정사각형은 직사각형의 일종
// 정사각형 is a 직사각형

// 기초클래스
class Rectangle {
private:
	int len1;
	int len2;
public:
	Rectangle(int l1, int l2)
		:len1(l1), len2(l2){}

	void ShowArea() {
		cout << "면적: " << len1 * len2 << endl;
	}
};

// 유도클래스
class Square : public Rectangle {
private:
public:
	Square(int num) :
		Rectangle(num, num){}
};

int main() {
	Rectangle rec(4, 3);
	rec.ShowArea(); // 면적: 12

	Square sqr(7);
	sqr.ShowArea(); // 면적: 49
	return 0;
}