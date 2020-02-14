#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAX_ACCOUNT 100
using namespace std;


class Account {
private:
	const int accountNum;
	char* name;
protected:
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

	virtual bool DepositMoney(int money) {
		cout << "[��   ��]" << endl;
		if (money > 0) {
			cout << "�ԱݿϷ�(step1)" << endl;
			balance += money;
			return true;
		}
		else {
			cout << "�߸��� �Ա��Դϴ�." << endl << endl;
			return false;
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

	virtual void ShowAllAccInfo() const {
		cout << endl;
		cout << "����ID: " << accountNum << endl;
		cout << "��  ��: " << name << endl;
		cout << "��  ��: " << balance << endl;
	}

	~Account() {
		delete[] name;
	}
};

class NormalAccount : public Account {
private:
	double interestRate;
public:
	NormalAccount(int accountNum, char* name, int balance, double rate)
		:Account(accountNum, name, balance), interestRate(rate){}

	double GetInterestRate()const {
		return interestRate;
	}

	bool DepositMoney(int money) {
		if (Account::DepositMoney(money)) {
			if (money > 0) {
				balance += (int)((money) * (interestRate / 100));
				return true;
			}
			else {
				cout << "�߸��� �Ա��Դϴ�." << endl << endl;
				return false;
			}
		}
	}

	virtual void ShowAllAccInfo() const{
		Account::ShowAllAccInfo();
		cout << "������: " << interestRate << endl;
	}
};

class HighCreditAccount : public NormalAccount {
private:
	int grade;
public:
	HighCreditAccount(int accountNum, char* name, int balance, double rate, int myGrade)
		:NormalAccount(accountNum, name, balance, rate), grade(myGrade){}

	bool DepositMoney(int money) {

		if (NormalAccount::DepositMoney(money)) {
			double bonusRate[3] = { 0.07, 0.04, 0.02 };
			if (money > 0) {
				balance += (int)(money * bonusRate[grade - 1]);
				return true;
			}
			else {
				cout << "�߸��� �Ա��Դϴ�." << endl << endl;
				return false;
			}
		}
	}


	virtual void ShowAllAccInfo() const {
		NormalAccount::ShowAllAccInfo();
		cout << "��  ��: " << grade << endl << endl;
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

	int ShowAccountMenu() {
		cout << endl;
		cout << "[������������]" << endl;
		cout << "1.���뿹�ݰ���  2.�ſ�ŷڰ���" << endl;

		int num;
		cout << "����: ";
		cin >> num;
		return num;
	}

	void MakeNormalAccount() {
		int accountNum;
		char name[20];
		int balance;
		double rate;

		cout << "[���°���]" << endl;
		cout << "����ID: ";
		cin >> accountNum;

		cout << "�̸�: ";
		cin >> name;

		cout << "�Աݾ�: ";
		cin >> balance;

		cout << "������: ";
		cin >> rate;
		cout << endl;

		account[accNum++] = new NormalAccount(accountNum, name, balance, rate);
	}

	void MakeHighCreditAccount() {
		int accountNum;
		char name[20];
		int balance;
		double rate;
		int grade;

		cout << "[���°���]" << endl;
		cout << "����ID: ";
		cin >> accountNum;

		cout << "�̸�: ";
		cin >> name;

		cout << "�Աݾ�: ";
		cin >> balance;

		cout << "������: ";
		cin >> rate;
		
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> grade;
		cout << endl;

		account[accNum++] = new HighCreditAccount(accountNum, name, balance, rate, grade);
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
	int subchoice;
	while (true) {
		choice = handler.ShowMenu();
		switch (choice) {
		case MENU::ACCOUNT:
			subchoice = handler.ShowAccountMenu();
			if (subchoice == 1) {
				handler.MakeNormalAccount();
			}
			else if (subchoice == 2) {
				handler.MakeHighCreditAccount();
			}
			else {
				cout << "�߸��� �Է�" << endl;
			}
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
