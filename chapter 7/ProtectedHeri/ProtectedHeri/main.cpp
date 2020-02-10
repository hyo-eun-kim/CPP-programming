#include <iostream>
using namespace std;

class Base {
private:
	int num1;
protected:
	int num2;
public:
	int num3;
public:
	Base(int n3) {
		num3 = n3;
		num1 = 0;
		num2 = 0;
	}

	Base(int n2, int n3)
		:num2(n2), num3(n3) {
		num1 = 0;
	}

	Base(int n1, int n2, int n3)
		:num1(n1), num2(n2), num3(n3){}
};

class Derived1 : public Base {
public:
	// num1은 유도클래스에서 접근 가능 + 클래스 외부에서 접근 가능 (public)
	// num2은 유도클래스에서 접근 가능 + 클래스 외부에서 접근 불가 (protected)
	// num3은 유도클래스에서 접근 불가
	Derived1(int n2, int n3)
		:Base(n2, n3) {}


	void Show() const {
		cout << num2 << endl;
		cout << num3 << endl;
	}
};

class Derived2 : protected Base {
public:
	// num1은 유도클래스에서 접근 가능 + 클래스 외부에서 접근 불가 (protected)
	// num2은 유도클래스에서 접근 가능 + 클래스 외부에서 접근 불가 (protected)
	// num3은 유도클래스에서 접근 불가
	Derived2(int n2, int n3)
		:Base(n2, n3) {}


	void Show() const {
		//cout << num1 << endl;
		cout << num2 << endl;
		cout << num3 << endl;
	}
};

class Derived3 : private Base {
public:
	// num1은 유도클래스에서 접근 불가 + 클래스 외부에서 접근 불가 (private)
	// num2은 유도클래스에서 접근 불가 + 클래스 외부에서 접근 불가 (private)
	// num3은 유도클래스에서 접근 불가
	Derived3(int n2, int n3)
		:Base(n2, n3) {}


	void Show() const {
		//cout << num1 << endl;
		cout << num2 << endl;
		cout << num3 << endl;
	}
};


int main(void) {

	Derived1 obj1(10, 20);
	obj1.Show();
	cout << obj1.num3 << endl;

	Derived2 obj2(30, 40);
	obj2.Show();

	Derived3 obj3(50, 60);
	obj3.Show();

	return 0;
}