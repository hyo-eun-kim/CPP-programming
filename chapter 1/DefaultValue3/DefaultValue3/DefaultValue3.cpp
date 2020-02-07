#include <iostream>

// �Ű������� default���� �����ϴ� �� �ƴ϶�
// �Լ� overloading�� �̿��� �����غ���

int BoxVolume(int num1, int num2, int num3) {
	return num1 * num2 * num3;
}

int BoxVolume(int num1, int num2) {
	return num1 * num2;
}

int BoxVolume(int num1) {
	return num1;
}

int main(void) {

	std::cout << BoxVolume(3, 3, 3) << std::endl; // 27
	std::cout << BoxVolume(5, 5) << std::endl; // 25
	std::cout << BoxVolume(7) << std::endl; // 7

	return 0;
}