#include <iostream>
using namespace std;

// reference�� �̿��� �Լ� �ܺ��� ������ ������ �� �ְ� �Ǿ���
// C++������ �ּҸ� �̿��� call by reference�� �����ڸ� �̿��� call by reference�� �ִ�.

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