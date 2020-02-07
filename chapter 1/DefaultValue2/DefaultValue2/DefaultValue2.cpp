#include <iostream>

// 매개변수의 default값은 함수의 "선언"부분에만 기재하면 된다.
int BoxVolumn(int length, int width=1, int height=1);

int main(void) {

	std::cout << BoxVolumn(3, 3, 3) << std::endl; // 27
	std::cout << BoxVolumn(5, 5) << std::endl; // 25 = BoxVolumn(5, 5, 1)
	std::cout << BoxVolumn(7) << std::endl; // 7 = BoxVolumn(7, 1, 1)
	// std::cout << BoxVolumn() << std::endl; 

	// 모든 매개변수에 default값이 지정된 것이 아니기 때문에 
	// 어떠한 인자도 주지 않으면 컴파일 에러로 이어진다.

	return 0;
}

// 함수의 정의에서는 매개변수의 default값을 지정해 줄 필요가 없다.
int BoxVolumn(int length, int width, int height) {

	return length * width * height;
}