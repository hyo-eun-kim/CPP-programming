#include <iostream>
using namespace std;

int main(void) {
	int num = 10;
	int i = 0;

	cout << "true: " << true << endl; // 1
	cout << "false: " << false << endl; // 0

	while (true) {
		cout << i++ << endl; // 0 1 2 3 4 5 6 7 8 9 10
		if (i > num)
			break;
		cout << endl;
	}

	cout << "sizeof 1: " << sizeof(1) << endl; // 4 bytes
	cout << "sizeof 0: " << sizeof(0) << endl; // 4 bytes
	cout << "sizeof true: " << sizeof(true) << endl; // 1 byte
	cout << "sizeof false: " << sizeof(false) << endl; // 1 byte

	// 여기서 주의해야 할 것은 true는 1이 아니며, fale 또한 0이 아니다.
	// 이전에 참을 표현하기 위해 1을, 거짓을 표현하기 위해 9을 사용했기 때문에
	// 출력하는 경우에 정수의 형태로 형변환이 되어 1과 0으로 출력되는 것이다.

	return 0;
}