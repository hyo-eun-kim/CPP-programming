#include <iostream>

// C에서 매크로함수가 있다면 C++에서는 인라인함수가 있다!
// 하지만 완전히 동일한 건 아니다.

// 1. 매크로함수는 전처리기에 의해 처리되지만 인라인함수는 컴파일러에 의해 처리되기 때문이다.
// 우리가 함수 앞에 'inline' 키워드를 적어도 컴파일러가 불필요하다 생각하면 인라인 처리하지 않는다.
// 반대로, 우리가 inline를 적지 않아도 컴파일러가 필요하다고 판단하면 인라인 처리한다.

// 2. 매크로함수는 자료형에 독립적이지만, 인라인함수는 자료형에 의존적이다.
// (나중에 '템플릿'을 이용하면 자료형에 의존적이지 않은 함수가 완성된다.)

inline int SQUARE(int num) {
	return num * num;
}

int main(void) {

	std::cout << SQUARE(5) << std::endl; // 25
	std::cout << SQUARE(12) << std::endl; // 144

	return 0;
}