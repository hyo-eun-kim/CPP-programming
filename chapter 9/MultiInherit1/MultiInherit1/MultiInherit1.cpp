#include <iostream>
using namespace std;

class BaseOne {
private:
	int num;
public:
	void SimpleFuncOne() {
		cout << "BaseOne" << endl;
	}
};

class BaseTwo {
private:
	int num;
public:
	void SimpleFuncTwo() {
		cout << "BaseTwo" << endl;
	}
};

// 두 개 이상의 클래스를 상속하는 -> 다중상속
class Derived : public BaseOne, public BaseTwo{
private:
	int num;
public:
	void SimpleFunc() {
		SimpleFuncOne(); // BaseOne클래스의 멤버함수
		SimpleFuncTwo(); // BaseTwo클래스의 멤버함수
	}
};

int main() {
	Derived obj;
	obj.SimpleFunc();

	return 0;
}