#include <iostream>
#include "Banking.h"

using namespace std;
typedef struct Accout {
	int num;
	int money;
	char name[50];
} Account;

Account account[100];
int i = 0; // 등록고객의 수 저장하는 전역변수


void OpenAccount(void) {
	cout << '\n' << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> account[i].num;
	cout << "이름 :";
	cin >> account[i].name;
	cout << "입금액: ";
	cin >> account[i].money;
	::i++;
}
void Deposit(void) {
	int num, money;
	cout << '\n' << "[입 금]" << endl;
	cout << "계좌ID: ";
	cin >> num;
	cout << "입금액: ";
	cin >> money;
	for (int i = 0; i <= ::i; i++) {
		if (account[i].num == num)
			account[i].money += money;
	}

	cout << "입금완료" << endl;

}
void Withdraw(void) {
	int num, money;
	cout << '\n' << "[출 금]" << endl;
	cout << "계좌ID: ";
	cin >> num;
	cout << "출금액: ";
	cin >> money;
	for (int i = 0; i <= ::i; i++) {
		if (account[i].num == num)
			if (account[i].money - money < 0) {
				cout << "잔액이 부족합니다" << endl;
			}
			else {
				account[i].money -= money;
				cout << "출금완료" << endl;
			}
	}
}
void ShowMoney(void) {
	int num;
	cout << '\n' << "계좌ID: ";
	cin >> num;
	for (int i = 0; i <= ::i; i++) {
		if (account[i].num == num) {
			cout << "이름: " << account[i].name << endl;
			cout << "잔액: " << account[i].money << endl;
		}
	}
}

int ShowMenu(void) {
	cout << '\n' << "----- Menu -----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;

	int button;
	cout << "선택: ";
	cin >> button;
	return button;
}