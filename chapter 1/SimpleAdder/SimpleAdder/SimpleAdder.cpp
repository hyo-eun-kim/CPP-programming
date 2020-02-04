#include <iostream>

int main(void) {

	// std::cout (console out)
	// std::cin  (console input)

	// 변수의 선언이 어디서든 가능하다. 
	// C에서는 함수 위쪽에 변수를 선언해야 했지만 (새로운 표준에서는 변수선언의 위치에 제한 두지 X)
	// C++에서는 함수 내 어디든 선언이 가능하다. (처음부터 함수 위쪽에 작성해야 한다는 규칙이 없었다.)
	
	// 별도의 format을 지정하지 않고 데이터의 입력과 출력이 가능하다.

	int val1;
	std::cout << "첫 번째 숫자입력: ";
	std::cin >> val1; // 입력받은 숫자를 변수 val1에 저장

	int val2;
	std::cout << "두 번째 숫자입력: ";
	std::cin >> val2; // 입력받은 숫자를 변수 val2에 저장

	std::cout << "덧셈결과: " << val1 + val2 << std::endl;

	char name[100];
	char dept[100];
	std::cout << "이름과 학과를 순서대로 입력해주세요 > ";
	std::cin >> name >> dept;
	
	std::cout << dept << "학과 " << name << "학생" << std::endl;

	return 0;
}