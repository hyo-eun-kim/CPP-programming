#include <iostream>

// '::' �����ڸ� '�������� ������'��� �ϸ�, �̸������� ������ �� ����Ѵ�.

namespace BestCom {
	void SimpleFunc(void) {
		std::cout << "BestCom�� ������ SImpleFunc" << std::endl;
	}
}

namespace ProgCom {
	void SimpleFunc(void) {
		std::cout << "ProgCom�� ������ SimpleFUnc" << std::endl;
	}
}

int main(void) {

	BestCom::SimpleFunc(); // BestCom�� ������ SImpleFunc
	ProgCom::SimpleFunc(); // ProgCom�� ������ SimpleFUnc

	return 0;
}