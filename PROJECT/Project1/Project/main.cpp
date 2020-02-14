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
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> account->accountNum;
	cout << "이름: ";
	cin >> account->name;
	cout << "입금액: ";
	cin >> account->balance;
	cout << endl;
}

void DepositMoney(Account* account) {
	int money;
	cout << "입금액: ";
	cin >> money;
	if (money > 0) {
		account->balance += money;
	}
	else {
		cout << "잘못된 입금입니다." << endl << endl;
	}
}

void WithdrawMoney(Account* account) {
	int money;
	cout << "출금액: ";
	cin >> money;
	if (money > 0 && (account->balance > money)) {
		account->balance -= money;
	}
	else {
		cout << "잘못된 출금입니다." << endl << endl;
	}
}

void ShowAllAccInfo(Account* account, int accNum) {

	for (int i = 0; i < accNum; i++) {
		cout << "계좌ID: " << account[i].accountNum << endl;
		cout << "이  름: " << account[i].name << endl;
		cout << "잔  액: " << account[i].balance << endl << endl;
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
			cout << "계좌ID: ";
			cin >> accNumInput;
			for (int i = 0; i < accNum; i++) {
				if (accNumInput == account[i].accountNum) {
					DepositMoney(&account[i]);
					break;
				}
			}
			break;
		case 3:
			cout << "계좌ID: ";
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
			cout << "종료합니다" << endl << endl;
			return 0;
		default:
			cout << "다시 입력해주세요." << endl << endl;
		}
	}
}

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
