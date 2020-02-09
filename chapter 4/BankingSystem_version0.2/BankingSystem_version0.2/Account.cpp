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
	cout << "�̸� > ";
	cin >> nameInput;
	cout << "�Ա� > ";
	cin >> money;

	this->name = new char[strlen(nameInput) + 1];
	strcpy(this->name, nameInput);
	this->accountNum = accountNumber;
	this->money = money;
	cout << "���¹�ȣ > " << accountNumber++ << endl;
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
	cout << "�Ա��� �ݾ� > ";
	cin >> money;

	if (money >= 0) {
		this->money += money;
		return true;
	}
	else {
		cout << "�߸��� �Ա�" << endl;
		return false;
	}
}

bool Account::withdraw() {
	int money;
	cout << "����� �ݾ� > ";
	cin >> money;
	if (this->money - money >= 0) {
		this->money -= money;
		return true;
	}
	else {
		cout << "�ܾ��� �����մϴ�" << endl;
		return false;
	}
}

void Account::show() const {
	cout << "[���¹�ȣ] " << accountNum << endl;
	cout << "[��    ��] " << name << endl;
	cout << "[��    ��] " << money << endl;
	cout << endl;
}

Account::~Account() {
	delete[] name;
}