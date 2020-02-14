#include <iostream>
using namespace std;

// 가상함수의 동작원리

class AAA {
private:
	int num;
public:
	virtual void Func1() {
		cout << "AAA::Func1()" << endl;
	}
};

class BBB : public AAA {
private:
	int num;
public: 
	virtual void Func1() {
		cout << "BBB::Func1()" << endl;
	}
};

// 가상함수(virtual)가 클래스에 하나 이상 존재하는 경우 -> 가상함수 테이블(V-table)이 만들어진다.
// 멤버함수를 호출할 때 이 V-table을 참고하게 된다.
// 이 때 B 클래스에서 가상함수가 오버라이딩 된 경우 기초클래스(A)의 가상함수는 B 클래스의 V-table에 저장되지 않는다.
// 아래 예제에서 확인할 수 있듯이 BBB 클래스의 V-table에는 AAA::Func1()의 정보가 없고, 오버라이딩 된 BBB::Func1()의 정보만 있다.
// 따라서 BBB 객체의 포인터는 BBB::Func1()을 호출하는 것이다.

int main(void) {
	AAA* a = new AAA();
	BBB* b = new BBB();

	a->Func1(); // AAA::Func1()
	b->Func1(); // BBB::Func1()

	return 0;
}