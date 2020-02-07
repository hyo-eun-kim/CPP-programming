#include <iostream>

namespace BestCom {
	void SimpleFunc(void);
}

namespace BestCom {
	void PrettyFunc(void);
}

namespace ProgCom {
	void SimpleFunc(void);
}

int main(void) {

	BestCom::SimpleFunc();

	return 0;
}

void BestCom::SimpleFunc(void) {
	std::cout << "BestCom의 SimpleFunc()" << std::endl;
	PrettyFunc(); // 동일 namespace
	ProgCom::SimpleFunc(); // 다른 namespace

}

void BestCom::PrettyFunc(void) {
	std::cout << "Pretty" << std::endl;
}

void ProgCom::SimpleFunc(void) {
	std::cout << "ProgCom의 SImpleFunc()" << std::endl;
}
