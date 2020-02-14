#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

int AccountHanlder::ShowMenu() {
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

int AccountHanlder::ShowAccountMenu() {
	cout << endl;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌  2.신용신뢰계좌" << endl;

	int num;
	cout << "선택: ";
	cin >> num;
	return num;
}

void AccountHanlder::MakeNormalAccount() {
	int accountNum;
	char name[20];
	int balance;
	double rate;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accountNum;

	cout << "이름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> balance;

	cout << "이자율: ";
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

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accountNum;

	cout << "이름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> balance;

	cout << "이자율: ";
	cin >> rate;

	cout << "신용등급(1toA, 2toB, 3toC): ";
	cin >> grade;
	cout << endl;

	account[accNum++] = new HighCreditAccount(accountNum, name, balance, rate, grade);
}

void AccountHanlder::DepositMoney() {
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

void AccountHanlder::WithdrawMoney() {
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