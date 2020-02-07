// �Լ� �����ε�
// C++������ �Լ��� �̸��� �Ű������� ������ ��� Ȱ���ϱ� ������
// �Լ����� �����ص� �Ű������� �ٸ��ٸ� �Լ��� ���ǵ� �� �ִ�.

// overloading�� ����
// 1. "�Լ��� ����"
// 2. �Ű������� "��" �ٸ��ų�
// 3. �Ű������� "�ڷ���"�� �ٸ��ų�
// 4. "��ȯ���� ����"�ؾ� �Ѵ�. (�Լ���� �Ű����� ������ Ȱ���Ͽ� �Լ��� �����ϹǷ�)

#include <iostream>

void MyFunc(void) {
	std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c) {
	std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int a, int b) {
	std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main(void) {

	MyFunc(); // MyFunc(void) called
	MyFunc('a'); // MyFunc(char c) called
	MyFunc(1, 2); // MyFunc(int a, int b) called

	return 0;
}
