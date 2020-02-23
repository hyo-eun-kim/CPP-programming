#include <iostream>
using namespace std;

class First {
private:
	int num1, num2;
public:
	First(int n1=0, int n2=0)
		:num1(n1), num2(n2){}
	void ShowData() {
		cout << num1 << ", " << num2 << endl;
	}
};

class Second : public First {
private:
	int num3, num4;
public:
	Second(int n1=0, int n2=0, int n3=0, int n4=0)
		:First(n1, n2), num3(n3), num4(n4){}
	void ShowData() {
		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}
};

int main(void) {

	Second obj1(10, 20, 30, 40);
	Second obj2;

	obj2 = obj1; 
	obj2.ShowData(); // 10, 20, 30, 40

	// 유도클래스에서 대입연산자를 오버로딩하지 않은 경우
	// 유도클래스의 default 대입연산자가 기초클래스의 default 대입연산자를 호출하여
	// 기초클래스의 멤버변수도 복사된다.
}