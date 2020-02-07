#include <iostream>
using namespace std;

// reference를 이용해 함수 외부의 변수에 접근할 수 있게 되었다
// C++에서는 주소를 이용한 call by reference와 참조자를 이용한 call by reference가 있다.

void SwapByRef(int& num1, int& num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

int main(void) {

	int val1 = 20;
	int val2 = 10;

	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	SwapByRef(val1, val2);

	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	return 0;

}