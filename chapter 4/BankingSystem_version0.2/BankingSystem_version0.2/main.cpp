#include "Account.h"
#include <iostream>
using namespace std;

extern  int joinCount;
extern int accountNumber;

// 1. ���°��� (���¹�ȣ, ���̸�, �ܾ�)
// 2. �Ա�
// 3. ���
// 4. �ܾ���ȸ 

int ShowMenu() {
	cout << "----- Menu -----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. ��������" << endl;
	cout << "5. ��    ��" << endl;

	int choice;
	cout << "���� > ";
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
				cout << "���¹�ȣ: ";
				cin >> input;
				for (int i = 0; i <= joinCount; i++) {
					if (account[i]->GetAccountNum() == input) {
						account[i]->deposit();
					}
				}
				break;
			case 3:
				cout << "���¹�ȣ: ";
				cin >> input;
				for (int i = 0; i <= joinCount; i++) {
					if (account[i]->GetAccountNum() == input) {
						account[i]->withdraw();
					}
				}
				break;
			case 4:
				cout << "���¹�ȣ: ";
				cin >> input;
				
				for (int i = 0; i <= joinCount; i++) {
					cout << account[i]->GetAccountNum() << endl;
					if (account[i]->GetAccountNum() == input) {
						account[i]->show();
					}
				}
				break;
			default:
				cout << "�ٽ� �Է����ּ���" << endl;
				choice = ShowMenu();
			}
		}
	}
	cout << "���α׷��� ����Ǿ����ϴ�. " << endl;
	return 0;
}