// ǥ�� ��������� ���𿡼��� Ȯ���ڸ� ����
// ���� ������ ǥ�� ���̺귯���� ���ο� ǥ�� ���̺귯���� �����ϱ� ���� .h �� ������ ����
// #include <iostream.h> �� ���� ǥ�� ���̺귯���� �ǹ��Ѵ�.

#include <iostream>

int main(void) {

	// std::cout ������ ����� �͵��� �����Ѵ�.
	// std::endl �� ������ �ǹ��Ѵ�.
	std::cout << "Hello World!" << std::endl;
	std::cout << "Hello " << "World!" << std::endl;

	// ������ ����� �� ���Ĺ��ڸ� �̿��� �ʿ䰡 ����. 
	// (C������ �ϳ��ϳ� ������Ÿ�Կ� ���� �������־�� �߾���.)
	int num = 20;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;

	return 0;
}