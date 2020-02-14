#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

int AccountHanlder::ShowMenu() {
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

int AccountHanlder::ShowAccountMenu() {
	cout << endl;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ���  2.�ſ�ŷڰ���" << endl;

	int num;
	cout << "����: ";
	cin >> num;
	return num;
}

void AccountHanlder::MakeNormalAccount() {
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

void AccountHanlder::MakeHighCreditAccount() {
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

void AccountHanlder::DepositMoney() {
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

void AccountHanlder::WithdrawMoney() {
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

void AccountHanlder::ShowAccount() {
	for (int i = 0; i < accNum; i++) {
		account[i]->ShowAllAccInfo();
	}
}

AccountHanlder::~AccountHanlder() {
	for (int i = 0; i < accNum; i++) {
		delete account[i];
	}
}