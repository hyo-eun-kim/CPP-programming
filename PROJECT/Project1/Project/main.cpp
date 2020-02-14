#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAX_ACCOUNT 100
using namespace std;
/*
class Account {
private:
	int accountNum;
	char name[20];
	int balance;
public:
	Account()
};
*/

struct Account {
	int accountNum;
	char name[20];
	int balance;
};

void MakeAccount(Account* account) {
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> account->accountNum;
	cout << "�̸�: ";
	cin >> account->name;
	cout << "�Աݾ�: ";
	cin >> account->balance;
	cout << endl;
}

void DepositMoney(Account* account) {
	int money;
	cout << "�Աݾ�: ";
	cin >> money;
	if (money > 0) {
		account->balance += money;
	}
	else {
		cout << "�߸��� �Ա��Դϴ�." << endl << endl;
	}
}

void WithdrawMoney(Account* account) {
	int money;
	cout << "��ݾ�: ";
	cin >> money;
	if (money > 0 && (account->balance > money)) {
		account->balance -= money;
	}
	else {
		cout << "�߸��� ����Դϴ�." << endl << endl;
	}
}

void ShowAllAccInfo(Account* account, int accNum) {

	for (int i = 0; i < accNum; i++) {
		cout << "����ID: " << account[i].accountNum << endl;
		cout << "��  ��: " << account[i].name << endl;
		cout << "��  ��: " << account[i].balance << endl << endl;
	}
}

int ShowMenu();
int accNum;

int main(void) {

	Account account[MAX_ACCOUNT];
	
	int choice;
	int accNumInput;
	while (true) {
		choice = ShowMenu();
		switch (choice) {
		case 1:
			MakeAccount(&account[accNum++]);
			break;
		case 2:
			cout << "����ID: ";
			cin >> accNumInput;
			for (int i = 0; i < accNum; i++) {
				if (accNumInput == account[i].accountNum) {
					DepositMoney(&account[i]);
					break;
				}
			}
			break;
		case 3:
			cout << "����ID: ";
			cin >> accNumInput;
			for (int i = 0; i < accNum; i++) {
				if (accNumInput == account[i].accountNum) {
					WithdrawMoney(&account[i]);
					break;
				}
			}
			break;
		case 4:
			ShowAllAccInfo(account, accNum);
			break;
		case 5:
			cout << "�����մϴ�" << endl << endl;
			return 0;
		default:
			cout << "�ٽ� �Է����ּ���." << endl << endl;
		}
	}
}

int ShowMenu() {
	cout << "----- MENU -----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. �������" << endl;
	cout << "5. ��    ��" << endl;

	int num;
	cout << "����: ";
	cin >> num;
	return num;
}
