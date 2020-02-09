#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

int joinCount = 0;
int accountNumber = 20200101;


Account::Account() {
	accountNum = 0;
	name = NULL;
	money = 0;
}

void Account::openAccount() {
	char nameInput[100];
	int money;
	cout << "이름 > ";
	cin >> nameInput;
	cout << "입금 > ";
	cin >> money;

	this->name = new char[strlen(nameInput) + 1];
	strcpy(this->name, nameInput);
	this->accountNum = accountNumber;
	this->money = money;
	cout << "계좌번호 > " << accountNumber++ << endl;
}
char* Account::GetName() const {
	return name;
}
int Account::GetMoney() const {
	return money;
}

int Account::GetAccountNum() const {
	return accountNum;
}

bool Account::deposit() {
	int money;
	cout << "입금할 금액 > ";
	cin >> money;

	if (money >= 0) {
		this->money += money;
		return true;
	}
	else {
		cout << "잘못된 입금" << endl;
		return false;
	}
}

bool Account::withdraw() {
	int money;
	cout << "출금할 금액 > ";
	cin >> money;
	if (this->money - money >= 0) {
		this->money -= money;
		return true;
	}
	else {
		cout << "잔액이 부족합니다" << endl;
		return false;
	}
}

void Account::show() const {
	cout << "[계좌번호] " << accountNum << endl;
	cout << "[이    름] " << name << endl;
	cout << "[잔    액] " << money << endl;
	cout << endl;
}

Account::~Account() {
	delete[] name;
}