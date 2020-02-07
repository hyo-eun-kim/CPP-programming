#include <iostream>
using namespace std;

// 포인터가 가리키는 대상을 바꾸는 함수
void SwapPointer(int* (&p1), int* (&p2)) {
	int* tmp = p1;
	p1 = p2;
	p2 = tmp;
}

int main(void) {

	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	cout << "ptr1 > " << ptr1 << endl;
	cout << "ptr2 > " << ptr2 << endl;
	cout << "*ptr1 > " << *ptr1 << endl; // 5
	cout << "*ptr2 > " << *ptr2 << endl; // 10

	SwapPointer(ptr1, ptr2);
	cout << endl;

	cout << "ptr1 > " << ptr1 << endl;
	cout << "ptr2 > " << ptr2 << endl;
	cout << "*ptr1 > " << *ptr1 << endl; // 10
	cout << "*ptr2 > " << *ptr2 << endl; // 5

	return 0;
}