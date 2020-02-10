#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	// 생성자
	SoSimple(int n) :num(n) {};

	void SimpleFunc() {
		cout << "SimpleFunc: " << num << endl;
	}

	// const 키워드를 붙이는 것도 함수 오버로딩 중 하나!
	// (+인자의 데이터타입이나 인자의 수를 바꾸는 것은 물론)
	void SimpleFunc() const {
		cout << "const SimpleFunc: " << num << endl;
	}
};

// const 객체를 받기 때문에 const 멤버함수를 호출하게 된다.
void YourFunc(const SoSimple& obj) {
	obj.SimpleFunc();
}

int main(void) {

	SoSimple obj1(2);
	const SoSimple obj2(7); // const 객체

	obj1.SimpleFunc(); // 그냥 멤버함수 호출
	obj2.SimpleFunc(); // const 멤버함수 호출

	YourFunc(obj1); // const 멤버함수 호출
	YourFunc(obj2); // const 멤버함수 호출

	return 0;
}