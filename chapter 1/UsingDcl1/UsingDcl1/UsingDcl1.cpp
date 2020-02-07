#include <iostream>

namespace Hybrid {
	void HybFunc() {
		std::cout << "So Simple Function" << std::endl;
		std::cout << "In namespace Hybrid" << std::endl;
	}
}

int main(void) {

	// namespace Hybrid에 선언된 HybFunc을 호출할 때는 namepsace를 지정하지 않고 호출하겠다
	using Hybrid::HybFunc;
	HybFunc(); // 이름공간의 명시 없이 함수를 호출하고 있다.

	return 0;
}