#include <iostream>

// �����ͺ����� �̿��� const ������ ����Ű�� �غ���.
// �׸��� �� ������ ������ �����ϴ� �����ڸ� ��������.
// �̷��� ����� �����ͺ����� �����ڸ� �̿��� num�� ����� ���� �������.

int main(void) {

	const int num = 12;
	const int* p = &num;
	const int* (&ref) = p;

	std::cout << *p << std::endl;
	std::cout << *ref << std::endl;
	return 0;
}