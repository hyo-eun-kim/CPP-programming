#include <iostream>
#include "Banking.h"

using namespace std;
typedef struct Accout {
	int num;
	int money;
	char name[50];
} Account;

Account account[100];
int i = 0; // ��ϰ��� �� �����ϴ� ��������


void OpenAccount(void) {
	cout << '\n' << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> account[i].num;
	cout << "�̸� :";
	cin >> account[i].name;
	cout << "�Աݾ�: ";
	cin >> account[i].money;
	::i++;
}
void Deposit(void) {
	int num, money;
	cout << '\n' << "[�� ��]" << endl;
	cout << "����ID: ";
	cin >> num;
	cout << "�Աݾ�: ";
	cin >> money;
	for (int i = 0; i <= ::i; i++) {
		if (account[i].num == num)
			account[i].money += money;
	}

	cout << "�ԱݿϷ�" << endl;

}
void Withdraw(void) {
	int num, money;
	cout << '\n' << "[�� ��]" << endl;
	cout << "����ID: ";
	cin >> num;
	cout << "��ݾ�: ";
	cin >> money;
	for (int i = 0; i <= ::i; i++) {
		if (account[i].num == num)
			if (account[i].money - money < 0) {
				cout << "�ܾ��� �����մϴ�" << endl;
			}
			else {
				account[i].money -= money;
				cout << "��ݿϷ�" << endl;
			}
	}
}
void ShowMoney(void) {
	int num;
	cout << '\n' << "����ID: ";
	cin >> num;
	for (int i = 0; i <= ::i; i++) {
		if (account[i].num == num) {
			cout << "�̸�: " << account[i].name << endl;
			cout << "�ܾ�: " << account[i].money << endl;
		}
	}
}

int ShowMenu(void) {
	cout << '\n' << "----- Menu -----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;

	int button;
	cout << "����: ";
	cin >> button;
	return button;
}