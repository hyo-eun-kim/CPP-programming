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
		cout << "[입   금]" << endl;
		if (money > 0) {
			balance += money;
		}
		else {
			cout << "잘못된 입금입니다." << endl << endl;
		}
	}

	void WithdrawMoney(int money) {

		cout << endl;
		cout << "[출   금]" << endl;
		if (money > 0 && (balance >= money)) {
			balance -= money;
		}
		else {
			cout << "잘못된 출금입니다." << endl << endl;
		}
	}

	void ShowAllAccInfo() const {
		cout << endl;
		cout << "계좌ID: " << accountNum << endl;
		cout << "이  름: " << name << endl;
		cout << "잔  액: " << balance << endl << endl;
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
		cout << "1. 계좌개설" << endl;
		cout << "2. 입    금" << endl;
		cout << "3. 출    금" << endl;
		cout << "4. 계좌출력" << endl;
		cout << "5. 종    료" << endl;

		int num;
		cout << "선택: ";
		cin >> num;
		return num;
	}

	void MakeAccount() {
		int accountNum;
		char name[20];
		int balance;

		cout << "[계좌개설]" << endl;
		cout << "계좌ID: ";
		cin >> accountNum;

		cout << "이름: ";
		cin >> name;

		cout << "입금액: ";
		cin >> balance;
		cout << endl;

		account[accNum++] = new Account(accountNum, name, balance);
	}

	void DepositMoney() {
		int accNumInput;
		cout << "계좌ID: ";
		cin >> accNumInput;
		for (int i = 0; i < accNum; i++) {
			if (accNumInput == account[i]->GetAccountNum()) {
				int money;
				cout << "입금액: ";
				cin >> money;
				account[i]->DepositMoney(money);
				break;
			}
		}
	}

	void WithdrawMoney() {
		int accNumInput;
		cout << "계좌ID: ";
		cin >> accNumInput;
		for (int i = 0; i < accNum; i++) {
			if (accNumInput == account[i]->GetAccountNum()) {
				int money;
				cout << "출금액: ";
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
			cout << "종료합니다" << endl << endl;
			return 0;
		default:
			cout << "다시 입력해주세요." << endl << endl;
		}
	}
	return 0;
}
