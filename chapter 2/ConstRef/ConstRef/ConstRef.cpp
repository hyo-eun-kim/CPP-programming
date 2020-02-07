#include <iostream>

// 포인터변수를 이용해 const 변수를 가리키게 해보자.
// 그리고 이 포인터 변수를 참조하는 참조자를 선언하자.
// 이렇게 선언된 포인터변수와 참조자를 이용해 num에 저장된 값을 출력하자.

int main(void) {

	const int num = 12;
	const int* p = &num;
	const int* (&ref) = p;

	std::cout << *p << std::endl;
	std::cout << *ref << std::endl;
	return 0;
}