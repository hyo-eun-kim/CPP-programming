#include <iostream>

// '::' 연산자를 '범위지정 연산자'라고 하며, 이름공간을 지정할 때 사용한다.

namespace BestCom {
	void SimpleFunc(void) {
		std::cout << "BestCom이 정의한 SImpleFunc" << std::endl;
	}
}

namespace ProgCom {
	void SimpleFunc(void) {
		std::cout << "ProgCom이 정의한 SimpleFUnc" << std::endl;
	}
}

int main(void) {

	BestCom::SimpleFunc(); // BestCom이 정의한 SImpleFunc
	ProgCom::SimpleFunc(); // ProgCom이 정의한 SimpleFUnc

	return 0;
}