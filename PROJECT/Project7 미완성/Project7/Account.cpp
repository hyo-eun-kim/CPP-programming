#include "BankingCommonDecl.h"
#include "Account.h"


Account::Account(int accountNum, char* name, int balance)
	:accountNum(accountNum), balance(balance) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& account)
	:accountNum(account.accountNum), balance(account.balance) {
	name = new char[strlen(account.name) + 1];
	strcpy(name, account.name);
}

int Account::GetAccountNum() const {
	return accountNum;
}

void Account::WithdrawMoney(int money) {

	cout << endl;
	cout << "[출   금]" << endl;
	if (money > 0 && (balance >= money)) {
		balance -= money;
	}
	else {
		cout << "잘못된 출금입니다." << endl << endl;
	}
}



Account::~Account() {
	delete[] name;
}