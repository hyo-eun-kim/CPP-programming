// 표준 헤더파일의 선언에서는 확장자를 생략
// 또한 과거의 표준 라이브러리와 새로운 표준 라이브러리를 구분하기 위해 .h 를 붙이지 않음
// #include <iostream.h> 는 과거 표준 라이브러리를 의미한다.

#include <iostream>

int main(void) {

	// std::cout 다음에 출력할 것들을 나열한다.
	// std::endl 은 개행을 의미한다.
	std::cout << "Hello World!" << std::endl;
	std::cout << "Hello " << "World!" << std::endl;

	// 변수를 출력할 때 서식문자를 이용할 필요가 없다. 
	// (C에서는 하나하나 데이터타입에 따라 지정해주어야 했었다.)
	int num = 20;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;

	return 0;
}