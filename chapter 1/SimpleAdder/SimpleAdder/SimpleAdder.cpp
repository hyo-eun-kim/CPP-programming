#include <iostream>

int main(void) {

	// std::cout (console out)
	// std::cin  (console input)

	// ������ ������ ��𼭵� �����ϴ�. 
	// C������ �Լ� ���ʿ� ������ �����ؾ� ������ (���ο� ǥ�ؿ����� ���������� ��ġ�� ���� ���� X)
	// C++������ �Լ� �� ���� ������ �����ϴ�. (ó������ �Լ� ���ʿ� �ۼ��ؾ� �Ѵٴ� ��Ģ�� ������.)
	
	// ������ format�� �������� �ʰ� �������� �Է°� ����� �����ϴ�.

	int val1;
	std::cout << "ù ��° �����Է�: ";
	std::cin >> val1; // �Է¹��� ���ڸ� ���� val1�� ����

	int val2;
	std::cout << "�� ��° �����Է�: ";
	std::cin >> val2; // �Է¹��� ���ڸ� ���� val2�� ����

	std::cout << "�������: " << val1 + val2 << std::endl;

	char name[100];
	char dept[100];
	std::cout << "�̸��� �а��� ������� �Է����ּ��� > ";
	std::cin >> name >> dept;
	
	std::cout << dept << "�а� " << name << "�л�" << std::endl;

	return 0;
}