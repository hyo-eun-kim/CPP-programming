// 함수 오버로딩
// C++에서는 함수의 이름과 매개변수의 정보를 모두 활용하기 때문에
// 함수명이 동일해도 매개변수가 다르다면 함수가 정의될 수 있다.

// overloading의 조건
// 1. "함수명 동일"
// 2. 매개변수의 "수" 다르거나
// 3. 매개변수의 "자료형"이 다르거나
// 4. "반환형은 동일"해야 한다. (함수명과 매개변수 정보만 활용하여 함수를 구분하므로)

#include <iostream>

void MyFunc(void) {
	std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c) {
	std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int a, int b) {
	std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main(void) {

	MyFunc(); // MyFunc(void) called
	MyFunc('a'); // MyFunc(char c) called
	MyFunc(1, 2); // MyFunc(int a, int b) called

	return 0;
}
