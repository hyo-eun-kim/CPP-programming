#include <iostream>
using namespace std;

class First {
private:
public:
	void FirstFunc() {
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "First's SimpleFunc" << endl;
	}
};

class Second : public First {
private:
public:
	void SecondFunc() {
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "Second's SimpleFunc" << endl;
	}
};

class Third : public Second{
private:
public:
	void ThirdFunc() {
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "Third's SimpleFunc" << endl;
	}
};


int main(void) {

	Third obj;
	obj.FirstFunc();	// Third클래스는 First클래스를 간접상속
	obj.SecondFunc();	// Third클래스는 Second클래스를 직접상속
	obj.ThirdFunc();	// Third클래스의 멤버함수
	obj.SimpleFunc();	// 재정의된 가상함수

	Second& sref = obj;
	sref.FirstFunc();	
	sref.SecondFunc();
	sref.SimpleFunc();	// SimpleFunc()가 가상함수이기 때문에 참조자형에 따라서 함수를 호출하는 게 아니라
						// sref가 어떤 객체를 참조하고 있느냐에 따라 함수 호출!
	
	First& fref = obj;
	fref.FirstFunc();	// Second클래스, Third클래스의 멤버에는 접근 불가! (First형 reference이기 때문에)
	fref.SimpleFunc();	// SImpleFunc는 가상함수이기 때문에 참조하고 있는 Third클래스 객체의 멤버변수에 접근 가능!
}