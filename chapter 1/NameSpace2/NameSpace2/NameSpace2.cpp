#include <iostream>

// 이름공간을 사용하면서 함수의 선언과 정의를 따로 해보자.

namespace BestCom {
	void SimpleFunc(void);
}

namespace ProgCom {
	void SimpleFunc(void);
}

int main(void) {

	// '::' : 범위지정 연산자 (이름공간을 명시할 때 사용)
	BestCom::SimpleFunc(); // BestCom의 SimpleFunc()
	ProgCom::SimpleFunc(); // ProgCom의 SimpleFunc()

	return 0;
}

namespace BestCom {
	void SimpleFunc(void) {
		std::cout << "BestCom의 SimpleFunc()" << std::endl;
	}
}

namespace ProgCom {
	void SimpleFunc(void) {
		std::cout << "ProgCom의 SimpleFunc()" << std::endl;
	}
}