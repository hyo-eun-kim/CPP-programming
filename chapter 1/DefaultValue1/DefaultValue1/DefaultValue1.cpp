#include <iostream>

// ���޵Ǵ� ���ڴ� ���ʿ��� ���������� ä�����Ƿ�
// default ���� �����ʿ��� �������� ä������ �Ѵ�.
// �Լ��� ����� ���Ǹ� ������ ���, default���� "����"�κп��� ǥ���ϸ� �ȴ�.

// �Լ��� ����
int Adder(int num1 = 1, int num2 = 2);

int main(void) {
	
	std::cout << Adder() << std::endl; // 3
	std::cout << Adder(5) << std::endl; // 7
	std::cout << Adder(3, 5) << std::endl; // 8

	return 0;
}

// �Լ��� ����
int Adder(int num1, int num2) {
	return num1 + num2;
}