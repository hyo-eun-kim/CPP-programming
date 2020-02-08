#include <iostream>
using namespace std;

// 멤버 이니셜라이저를 사용하면 멤버변수가 선언과 동시에 초기화되는 것과 동일하다.
// 따라서 선언과 동시에 초기화 되어야 하는 const 변수나 reference도 
// 멤버 이니셜라이저를 사용하면 클래스의 멤버변수로 사용할 수 있게 되는 것이다.

// 아래 코드는 reference(참조자)를 클래스의 멤버변수로 사용한 예시이다.
// 코드에서 확인할 수 있듯이 멤버 이니셜라이저를 통해 참조자를 선언과 동시에 초기화하고 있다.

class AAA {
public:
	AAA() {
		cout << "empty object" << endl;
	}
	void Show() {
		cout << "class AAA" << endl;
	}
};

class BBB {
private:
	AAA& ref;
	const int& num;
public:
	BBB(AAA& r, const int& n)
		: ref(r), num(n) {

	}
	void Show() {
		ref.Show();
		cout << "and" << endl;
		cout << "I ref num " << num << endl;
	}
};

int main(void) {

	AAA aaa;
	BBB bbb(aaa, 5);
	bbb.Show();

	return 0;
}