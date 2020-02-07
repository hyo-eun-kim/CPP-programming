#include <iostream>

// 전달되는 인자는 왼쪽에서 오른쪽으로 채워지므로
// default 값은 오른쪽에서 왼쪽으로 채워져야 한다.
// 함수의 선언과 정의를 따로할 경우, default값은 "선언"부분에만 표현하면 된다.

// 함수의 선언
int Adder(int num1 = 1, int num2 = 2);

int main(void) {
	
	std::cout << Adder() << std::endl; // 3
	std::cout << Adder(5) << std::endl; // 7
	std::cout << Adder(3, 5) << std::endl; // 8

	return 0;
}

// 함수의 정의
int Adder(int num1, int num2) {
	return num1 + num2;
}