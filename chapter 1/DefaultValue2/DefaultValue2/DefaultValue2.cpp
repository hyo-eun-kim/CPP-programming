#include <iostream>

// �Ű������� default���� �Լ��� "����"�κп��� �����ϸ� �ȴ�.
int BoxVolumn(int length, int width=1, int height=1);

int main(void) {

	std::cout << BoxVolumn(3, 3, 3) << std::endl; // 27
	std::cout << BoxVolumn(5, 5) << std::endl; // 25 = BoxVolumn(5, 5, 1)
	std::cout << BoxVolumn(7) << std::endl; // 7 = BoxVolumn(7, 1, 1)
	// std::cout << BoxVolumn() << std::endl; 

	// ��� �Ű������� default���� ������ ���� �ƴϱ� ������ 
	// ��� ���ڵ� ���� ������ ������ ������ �̾�����.

	return 0;
}

// �Լ��� ���ǿ����� �Ű������� default���� ������ �� �ʿ䰡 ����.
int BoxVolumn(int length, int width, int height) {

	return length * width * height;
}