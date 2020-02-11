#include <iostream>
using namespace std;

// ���簢���� �ǹ��ϴ� Square Ŭ����
// ���簢���� �ǹ��ϴ� Rectangle Ŭ����
// ���簢���� ���簢���� ����
// ���簢�� is a ���簢��

// ����Ŭ����
class Rectangle {
private:
	int len1;
	int len2;
public:
	Rectangle(int l1, int l2)
		:len1(l1), len2(l2){}

	void ShowArea() {
		cout << "����: " << len1 * len2 << endl;
	}
};

// ����Ŭ����
class Square : public Rectangle {
private:
public:
	Square(int num) :
		Rectangle(num, num){}
};

int main() {
	Rectangle rec(4, 3);
	rec.ShowArea(); // ����: 12

	Square sqr(7);
	sqr.ShowArea(); // ����: 49
	return 0;
}