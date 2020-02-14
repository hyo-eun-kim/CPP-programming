#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAX_ACCOUNT 100
using namespace std;


class Account {
private:
	const int accountNum; 
	char* name;
	int balance;

public:

	Account(int accountNum, char* name, int balance)
		:accountNum(accountNum), balance(balance) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	Account(const Account& account)
		:accountNum(account.accountNum), balance(account.balance) {
		name = new char[strlen(account.name) + 1];
		strcpy(name, account.name);
	}

	int GetAccountNum() const {
		return accountNum;
	}

	void DepositMoney(int money) {

		cout << endl;
		cout << "[��   ��]" << endl;
		if (money > 0) {
			balance += money;
		}
		else {
			cout << "�߸��� �Ա��Դϴ�." << endl << endl;
		}
	}

	void WithdrawMoney(int money) {

		cout << endl;
		cout << "[��   ��]" << endl;
		if (money > 0 && (balance >= money)) {
			balance -= money;
		}
		else {
			cout << "�߸��� ����Դϴ�." << endl << endl;
		}
	}

	void ShowAllAccInfo() const {
		cout << endl;
		cout << "����ID: " << accountNum << endl;
		cout << "��  ��: " << name << endl;
		cout << "��  ��: " << balance << endl << endl;
	}

	~Account() {
		delete[] name;
	}
};


class AccountHanlder {
private:
	int accNum = 0;
	Account* account[MAX_ACCOUNT];
	

public:

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

	void MakeAccount() {
		int accountNum;
		char name[20];
		int balance;

		cout << "[���°���]" << endl;
		cout << "����ID: ";
		cin >> accountNum;

		cout << "�̸�: ";
		cin >> name;

		cout << "�Աݾ�: ";
		cin >> balance;
		cout << endl;

		account[accNum++] = new Account(accountNum, name, balance);
	}

	void DepositMoney() {
		int accNumInput;
		cout << "����ID: ";
		cin >> accNumInput;
		for (int i = 0; i < accNum; i++) {
			if (accNumInput == account[i]->GetAccountNum()) {
				int money;
				cout << "�Աݾ�: ";
				cin >> money;
				account[i]->DepositMoney(money);
				break;
			}
		}
	}

	void WithdrawMoney() {
		int accNumInput;
		cout << "����ID: ";
		cin >> accNumInput;
		for (int i = 0; i < accNum; i++) {
			if (accNumInput == account[i]->GetAccountNum()) {
				int money;
				cout << "��ݾ�: ";
				cin >> money;
				account[i]->WithdrawMoney(money);
				break;
			}
		}
	}

	void ShowAccount() {
		for (int i = 0; i < accNum; i++) {
			account[i]->ShowAllAccInfo();
		}
	}

	~AccountHanlder() {
		for (int i = 0; i < accNum; i++) {
			delete account[i];
		}
	}
};

namespace MENU {
	enum { ACCOUNT = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };
}

int main(void) {

	AccountHanlder handler;
	int choice;
	while (true) {
		choice = handler.ShowMenu();
		switch (choice) {
		case MENU::ACCOUNT:
			handler.MakeAccount();
			break;
		case MENU::DEPOSIT:
			handler.DepositMoney();
			break;
		case MENU::WITHDRAW:
			handler.WithdrawMoney();
			break;
		case MENU::SHOW:
			handler.ShowAccount();
			break;
		case MENU::EXIT:
			cout << "�����մϴ�" << endl << endl;
			return 0;
		default:
			cout << "�ٽ� �Է����ּ���." << endl << endl;
		}
	}
	return 0;
}
