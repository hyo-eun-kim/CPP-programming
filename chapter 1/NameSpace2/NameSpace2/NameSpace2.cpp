#include <iostream>

// �̸������� ����ϸ鼭 �Լ��� ����� ���Ǹ� ���� �غ���.

namespace BestCom {
	void SimpleFunc(void);
}

namespace ProgCom {
	void SimpleFunc(void);
}

int main(void) {

	// '::' : �������� ������ (�̸������� ����� �� ���)
	BestCom::SimpleFunc(); // BestCom�� SimpleFunc()
	ProgCom::SimpleFunc(); // ProgCom�� SimpleFunc()

	return 0;
}

namespace BestCom {
	void SimpleFunc(void) {
		std::cout << "BestCom�� SimpleFunc()" << std::endl;
	}
}

namespace ProgCom {
	void SimpleFunc(void) {
		std::cout << "ProgCom�� SimpleFunc()" << std::endl;
	}
}