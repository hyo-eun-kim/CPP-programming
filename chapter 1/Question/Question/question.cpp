#include <iostream>

int q1(void);
int q2(void);
int q3(void);
int q4(void);

int main(void) {

	q1();
	q2();
	q3();
	q4();

	return 0;
}

int q1(void) {

	// ����ڷκ��� 5���� ������ �Է¹޾Ƽ� �� ���� ���

	int sum = 0, input;
	for (int i = 0; i < 5; i++) {
		std::cout << i+1 << "��° ���� �Է�: ";
		std::cin >> input;
		sum += input;
	}

	std::cout << "�հ�: " << sum << std::endl;

	return 0;
}

int q2(void) {

	// ����ڷκ��� �̸��� ��ȭ��ȣ�� ���ڿ��� ���·� �Է� �޾�
	// �Է¹��� �����͸� �״�� ����ϴ� ���α׷�

	char name[100];
	char phone[100];

	std::cout << "�̸��� ��ȭ��ȣ�� �Է����ּ��� > ";
	std::cin >> name >> phone;

	std::cout << name << "���� �ڵ��� ��ȭ��ȣ�� " << phone << "�Դϴ�. " << std::endl;
	return 0;
}

int q3(void) {

	// ���� �ϳ��� �Է¹޾Ƽ� �� ���ڿ� �ش��ϴ� ������ ���

	int num;
	std::cout << "�� ���� ����ұ��? ";
	std::cin >> num;

	for (int i = 1; i <= 9; i++) {
		std::cout << num << " * " << i << " = " << num * i << std::endl;
	}

	return 0;
}

int q4(void) {

	// �Ŵ� 50������ �⺻ �޿��� ��ǰ �Ǹ� ������ 12%�� �ش��ϴ� ���� ����
	int sales;
	std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
	std::cin >> sales;
	if (sales != -1){
		while (sales != -1) {
			std::cout << "�̹� �� �޿�: " << 50 + sales * 0.12 << "����" << std::endl;
			std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
			std::cin >> sales;
		}
	}
	std::cout << "���α׷��� �����մϴ�." << std::endl;

	return 0;
}