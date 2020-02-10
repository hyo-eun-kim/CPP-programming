#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int AccountId = 1000;


class Account {
private:
	int accID;
	int balance;
	char* cusName;
public:
	static int accountId;
	static int accCnt;
public:
	Account():accID(0), balance(0), cusName(NULL) {};

	Account(const Account& copy)
		:accID(copy.accID), balance(copy.balance) {
		cusName = new char[strlen(copy.cusName) + 1]; // deep copy
		strcpy(cusName, copy.cusName); 
	}

	Account(int balance, const char* cusName)
		:balance(balance), accID(accountId) {
		this->cusName = new char[strlen(cusName) + 1]; // deep copy
		strcpy(this->cusName, cusName);

		cout << "계좌번호 > " << this->accID << endl << endl;

		Account::accountId++;
		Account::accCnt++;
	}
	~Account() {
		delete[] cusName;
	}

	int GetAccId() const{
		return accID;
	}


	bool Deposit() {
		int money;
		cout << "입금금액 > ";
		cin >> money;

		if (money >= 0) {
			this->balance += money;
			return true;
		}
		else {
			cout << "잘못된 입금입니다." << endl;
			return false;
		}
	}

	bool Withdraw() {
		int money;
		cout << "출금금액 > ";
		cin >> money;

		if (money < balance) {
			this->balance -= money;
			return true;
		}
		else {
			cout << "잘못된 출금입니다." << endl;
			return false;
		}
	}

	void Show() const{
		cout << "[계좌번호] " << accID << endl;
		cout << "[이    름] " << cusName << endl;
		cout << "[잔    액] " << balance << endl << endl;
	}

};


int Account::accCnt = 0;
int Account::accountId = 1000;

int ShowMenu() {
	cout << "----- Menu -----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌조회" << endl;
	cout << "5. 종    료" << endl << endl;

	int choice;
	cout << "입력 > ";
	cin >> choice;
	return choice;
}

int main(void) {

	int choice = 0;
	int inputAccNum = 0;
	Account* account[100];

	while (true) {
		choice = ShowMenu();
		switch (choice) {
		// 계좌개설 
		case 1:
			int balance;
			char cusName[100];

			cout << "이름 > "; cin >> cusName;
			cout << "입금 > "; cin >> balance;
			account[Account::accCnt] = new Account(balance, cusName);
			break;
		// 입금
		case 2:
			cout << "계좌번호 > ";
			cin >> inputAccNum;
			for (int i = 0; i < Account::accCnt; i++) {
				if ((account[i]->GetAccId()) == inputAccNum) {
					account[i]->Deposit();
				}
			}
			break;
		// 출금
		case 3:
			cout << "계좌번호 > ";
			cin >> inputAccNum;
			for (int i = 0; i < Account::accCnt; i++) {
				if (account[i]->GetAccId() == inputAccNum) {
					account[i]->Withdraw();
				}
			}
			break;
		// 계좌조회
		case 4:
			cout << "계좌번호 > ";
			cin >> inputAccNum;
			for (int i = 0; i < Account::accCnt; i++) {
				cout << account[i]->GetAccId() << endl;
				if (account[i]->GetAccId() == inputAccNum) {
					account[i]->Show();
				}
			}
			break;
		case 5:
			cout << "종료합니다." << endl;
			return 0;
		default:
			cout << "다시 입력해주세요." << endl;
		}

		
	}
	return 0;

}