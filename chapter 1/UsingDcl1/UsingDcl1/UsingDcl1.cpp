#include <iostream>

namespace Hybrid {
	void HybFunc() {
		std::cout << "So Simple Function" << std::endl;
		std::cout << "In namespace Hybrid" << std::endl;
	}
}

int main(void) {

	// namespace Hybrid�� ����� HybFunc�� ȣ���� ���� namepsace�� �������� �ʰ� ȣ���ϰڴ�
	using Hybrid::HybFunc;
	HybFunc(); // �̸������� ��� ���� �Լ��� ȣ���ϰ� �ִ�.

	return 0;
}