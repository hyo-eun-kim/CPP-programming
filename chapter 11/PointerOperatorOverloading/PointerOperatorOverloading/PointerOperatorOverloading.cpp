#include <iostream>
using namespace std;


class Number {
private:
	int num;
public:
	Number(int n = 0) :num(n) {};

	void ShowData() {
		cout << num << endl;
	}

	Number& operator*() {
		return *this;
	}

	Number* operator->() {
		return this;
	}
};

int main(void) {
	Number num(20); // 소멸자 호출 + 객체 생성
	num.ShowData(); // num 객체의 멤버함수에 접근

	// *은 객체에 접근
	// ->은 객체의 멤버에 접근


	// 연산자 오버로딩을 통해 num은 사실 객체임에도 불구하고 포인터변수처럼 사용됨
	(*num) = 30;		// 자기자신을 참조할 수 있는 참조자 반환
	num->ShowData();	// num->()은 자기자신의 주소값 반환
	(*num).ShowData();	// *num은 자기자신을 참조할 수 있는 참조자 반환
	return 0;
}