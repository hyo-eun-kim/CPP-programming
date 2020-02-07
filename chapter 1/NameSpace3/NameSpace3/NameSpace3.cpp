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
	std::cout << "BestCom�� SimpleFunc()" << std::endl;
	PrettyFunc(); // ���� namespace
	ProgCom::SimpleFunc(); // �ٸ� namespace

}

void BestCom::PrettyFunc(void) {
	std::cout << "Pretty" << std::endl;
}

void ProgCom::SimpleFunc(void) {
	std::cout << "ProgCom�� SImpleFunc()" << std::endl;
}
