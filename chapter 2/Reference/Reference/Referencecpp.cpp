#include <iostream>
using namespace std;

int main(void) {

	// 이미 선언된 변수에 &을 사용하면 그 변수의 주솟값을 반환하는 연산자이지만
	// 새로 선언되는 변수에 &을 사용하면 reference의 선언을 의미하게 된다.

	int num1 = 1020;
	int& num2 = num1; // num2는 num1의 reference
	// 결과적으로 num1이라 이름 붙어있는 메모리공간에 num2라는 이름이 하나 더 붙게 된 것이다.
	// 참조자는 변수를 대상으로만 선언이 가능하다.

	num2 = 3040;
	cout << "VAL: " << num1 << endl; // 3040
	cout << "REF: " << num2 << endl; // 3040

	cout << "VAL: " << &num1 << endl; // 00AFF778
	cout << "REF: " << &num2 << endl; // 00AFF778

	return 0;
}