// 생성자 (Constructor)
// 1. 클래스와 이름이 동일한 함수
// 2. 반환형이 없는 함수

// 생성자는 객체 생성 시 자동으로 딱 한 번 호출되는 함수
// 생성자(constructor) 역시 함수이므로 오버로딩이 가능하며, default값을 설정할 수 있다.

#include <iostream>
using namespace std;

class SimpleClass {
private:
	int num1;
	int num2;
public:
	SimpleClass() {
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n) {
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2) {
		num1 = n1;
		num2 = n2;
	}
	void Show() {
		cout << "num1: " << num1 << endl;
		cout << "num2: " << num2 << endl;
	}
};

int main(void) {
	SimpleClass c1;
	c1.Show();

	SimpleClass c2(2);
	c2.Show();

	SimpleClass c3(3, 5);
	c3.Show();
}