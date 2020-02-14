#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAX_ACCOUNT 100
using namespace std;


class Account {
private:
	const int accountNum; // �����ڸ� ���� ����� ���ÿ� �ʱ�ȭ�� �����ϹǷ� const ���� ����
	char* name;
	int balance;
public:

	// Constructor
	Account(int accountNum, char* name, int balance)
		:accountNum(accountNum), balance(balance) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	// ���������
	Account(const Account& account)
		:accountNum(account.accountNum), balance(account.balance) {
		name = new char[strlen(account.name) + 1];
		strcpy(name, account.name);
	}


	int GetAccountNum() const {
		return accountNum;
	}

	void DepositMoney(int money) {
		if (money > 0) {
			balance += money;
		}
		else {
			cout << "�߸��� �Ա��Դϴ�." << endl << endl;
		}
	}

	void WithdrawMoney(int money) {
		if (money > 0 && (balance >= money)) {
			balance -= money;
		}
		else {
			cout << "�߸��� ����Դϴ�." << endl << endl;
		}
	}

	void ShowAllAccInfo() const{
		cout << "����ID: " << accountNum << endl;
		cout << "��  ��: " << name << endl;
		cout << "��  ��: " << balance << endl << endl;
	}

	// Destructor
	~Account() {
		delete[] name;
	}
};




namespace MENU {
	enum { ACCOUNT = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };
}


int ShowMenu();
int accNum = 0;

int main(void) {

	Account* account[MAX_ACCOUNT];

	int choice;
	int accNumInput;
	while (true) {
		choice = ShowMenu();
		switch (choice) {
		case MENU::ACCOUNT:
			int accountNum;
			char name[20];
			int balance;

			cout << "[���°���]" << endl;
			cout << "����ID: ";
			cin >> accountNum;

			cout << "�̸�: ";
			cin >> name;

			cout << "�Աݾ�: ";
			cin >> balance;
			cout << endl;

			account[accNum++] = new Account(accountNum, name, balance);
			break;
		case MENU::DEPOSIT:
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
			break;
		case MENU::WITHDRAW:
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
			break;
		case MENU::SHOW:
			cout << "����ID: ";
			cin >> accNumInput;
			for (int i = 0; i < accNum; i++) {
				if (accNumInput == account[i]->GetAccountNum()) {
					account[i]->ShowAllAccInfo();
					break;
				}
			}
			break;
		case MENU::EXIT:
			cout << "�����մϴ�" << endl << endl;
			return 0;
		default:
			cout << "�ٽ� �Է����ּ���." << endl << endl;
		}
	}

	for (int i = 0; i < accNum; i++) {
		delete account[i];
	}
}

int ShowMenu() {
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
