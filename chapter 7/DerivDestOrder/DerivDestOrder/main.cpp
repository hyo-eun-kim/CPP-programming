#include <iostream>
using namespace std;

class Base {
private:
	int baseNum;
public:

	// void 생성자
	Base() :baseNum(20) {
		cout << "Base() : " << baseNum << endl;
	}

	Base(int num) :baseNum(num) {
		cout << "Base(int) : " << baseNum << endl;
	}

	void ShowBaseData() {
		cout << baseNum << endl;
	}

	~Base() {
		cout << "~Base() : " << baseNum << endl;
	}

};

// Base 클래스를 상속받은 Derived 클래스
class Derived : public Base {
private:
	int deriveNum;
public:
	Derived() {
		// 기초클래스의 생성자를 명시하지 않으면 void 생성자가 호출된다
		deriveNum = 30;
		cout << "Derived() : " << deriveNum << endl;
	}
	Derived(int num) {
		// 기초클래스의 생성자를 명시하지 않으면 void 생성자가 호출된다
		deriveNum = num;
		cout << "Derived(int) : " << deriveNum << endl;
	}
	Derived(int num1, int num2)
		:Base(num1), deriveNum(num2) {
		cout << "Derived(int, int) : " << deriveNum << endl;
	}

	void ShowDerivedData() {
		ShowBaseData();
		cout << deriveNum << endl << endl;
	}

	~Derived() {
		cout << "~Derived : " << deriveNum << endl;
	}
};

int main(void) {


	Derived obj1(15, 15);
	Derived obj2(27, 27);

	/*
	Base(int) : 15			// 기초클래스 생성자 실행
	Derived(int, int) : 15	// 유도클래스 생성자 실행
	Base(int) : 27			// 기초클래스 생성자 실행
	Derived(int, int) : 27	// 유도클래스 생성자 실행
	~Derived : 27			// 유도클래스 소멸자 실행
	~Base() : 27			// 기초클래스 소멸자 실행
	~Derived : 15			// 유도클래스 소멸자 실행
	~Base() : 15			// 기초클래스 소멸자 실행

	객체가 생성되었던 순서와 반대로 객체가 소멸된다.
	가장 나중에 생성되었던 객체가 가장 먼저 소멸된다.

	*/

	return 0;
}