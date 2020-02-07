#include <iostream>

// ��ø�� namespace
// "::" �������� ������

namespace Parent {
	int num = 1;
	namespace SubOne {
		int num = 2;
	}
	namespace SubTwo {
		int num = 3;
	}
}

int main(void) {

	std::cout << Parent::num << std::endl; // 1
	std::cout << Parent::SubOne::num << std::endl; // 2
	std::cout << Parent::SubTwo::num << std::endl; // 3

	return 0;
}