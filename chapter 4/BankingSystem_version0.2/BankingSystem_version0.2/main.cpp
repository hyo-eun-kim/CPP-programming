#include "Account.h"
#include <iostream>
using namespace std;

extern  int joinCount;
extern int accountNumber;

// 1. 계좌개설 (계좌번호, 고객이름, 잔액)
// 2. 입금
// 3. 출금
// 4. 잔액조회 

int ShowMenu() {
	cout << "----- Menu -----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보" << endl;
	cout << "5. 종    료" << endl;

	int choice;
	cout << "선택 > ";
	cin >> choice;
	return choice;
}

int main(void) {
	int choice;
	int input;
	Account* account[100];

	while(1) {
		choice = ShowMenu();
		if (choice == 5) {
			break;
		}
		else {
			switch (choice) {
			case 1:
				account[joinCount] = new Account;
				account[joinCount]->openAccount();
				break;
			case 2:
				cout << "계좌번호: ";
				cin >> input;
				for (int i = 0; i <= joinCount; i++) {
					if (account[i]->GetAccountNum() == input) {
						account[i]->deposit();
					}
				}
				break;
			case 3:
				cout << "계좌번호: ";
				cin >> input;
				for (int i = 0; i <= joinCount; i++) {
					if (account[i]->GetAccountNum() == input) {
						account[i]->withdraw();
					}
				}
				break;
			case 4:
				cout << "계좌번호: ";
				cin >> input;
				
				for (int i = 0; i <= joinCount; i++) {
					cout << account[i]->GetAccountNum() << endl;
					if (account[i]->GetAccountNum() == input) {
						account[i]->show();
					}
				}
				break;
			default:
				cout << "다시 입력해주세요" << endl;
				choice = ShowMenu();
			}
		}
	}
	cout << "프로그램이 종료되었습니다. " << endl;
	return 0;
}