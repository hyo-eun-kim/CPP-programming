#include <iostream>

int main(void) {

	// �� ���ڸ� �Է¹޾� �� �� ���̿� �����ϴ� �������� ���� ����Ͽ� ���

	int val1, val2;
	std::cout << "�� ���� �����Է�: ";
	std::cin >> val1 >> val2; 
	// �����̽�, ��, ���� �Է��� �������� ���еǾ� ����
	// ù ��° �Է��� val1��, �� ��° �Է��� val2�� ����ȴ�

	int sum = 0;
	if (val1 < val2) 
	{
		for (int i = val1 + 1; i < val2; i++)
			sum += i;
	}
	else
	{
		for (int i = val2 + 1; i < val1; i++)
			sum += i;
	}

	std::cout << "�� �� ������ ���� ��: " << sum << std::endl;
	return 0;
}