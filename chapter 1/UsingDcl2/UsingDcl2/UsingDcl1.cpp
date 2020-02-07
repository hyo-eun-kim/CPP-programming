#include <iostream>


// 함수 밖에 선언함으로써 전역의 형태로 삽입하였다.
using std::cin;
using std::cout;
using std::endl;

int main(void) {

	int num = 20;
	cout << "Hello World!" << endl;
	cout << "Hello " << "World!" << endl;
	cout << num << ' ' << 'A' << ' ' << 3.14 << endl;

	return 0;
}