#include <iostream>
using namespace std;

class BaseOne {
private:
	int num;
public:
	void SimpleFunc() {
		cout << "BaseOne" << endl;
	}
};

class BaseTwo {
private:
	int num;
public:
	void SimpleFunc() {
		cout << "BaseTwo" << endl;
	}
};

// 두 개 이상의 클래스를 상속하는 -> 다중상속
// 이 때 기초클래스의 멤버함수명이 동일하다면? 
// 어느 클래스의 함수인지 모호해짐 (ambiguous) 
// 따라서 어느 클래스의 멤버함수인지 명시해주어야 한다.

class Derived : public BaseOne, public BaseTwo {
private:
	int num;
public:
	void Func() {
		// SimpleFunc(); // 어느 클래스의 함수인지 인식하지 못함

		BaseOne::SimpleFunc(); // BaseOne클래스의 멤버함수
		BaseTwo::SimpleFunc(); // BaseTwo클래스의 멤버함수
	}
};

int main() {
	Derived obj;
	obj.Func();

	return 0;
}