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

		cout << "���¹�ȣ > " << this->accID << endl << endl;

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
		cout << "�Աݱݾ� > ";
		cin >> money;

		if (money >= 0) {
			this->balance += money;
			return true;
		}
		else {
			cout << "�߸��� �Ա��Դϴ�." << endl;
			return false;
		}
	}

	bool Withdraw() {
		int money;
		cout << "��ݱݾ� > ";
		cin >> money;

		if (money < balance) {
			this->balance -= money;
			return true;
		}
		else {
			cout << "�߸��� ����Դϴ�." << endl;
			return false;
		}
	}

	void Show() const{
		cout << "[���¹�ȣ] " << accID << endl;
		cout << "[��    ��] " << cusName << endl;
		cout << "[��    ��] " << balance << endl << endl;
	}

};


int Account::accCnt = 0;
int Account::accountId = 1000;

int ShowMenu() {
	cout << "----- Menu -----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. ������ȸ" << endl;
	cout << "5. ��    ��" << endl << endl;

	int choice;
	cout << "�Է� > ";
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
		// ���°��� 
		case 1:
			int balance;
			char cusName[100];

			cout << "�̸� > "; cin >> cusName;
			cout << "�Ա� > "; cin >> balance;
			account[Account::accCnt] = new Account(balance, cusName);
			break;
		// �Ա�
		case 2:
			cout << "���¹�ȣ > ";
			cin >> inputAccNum;
			for (int i = 0; i < Account::accCnt; i++) {
				if ((account[i]->GetAccId()) == inputAccNum) {
					account[i]->Deposit();
				}
			}
			break;
		// ���
		case 3:
			cout << "���¹�ȣ > ";
			cin >> inputAccNum;
			for (int i = 0; i < Account::accCnt; i++) {
				if (account[i]->GetAccId() == inputAccNum) {
					account[i]->Withdraw();
				}
			}
			break;
		// ������ȸ
		case 4:
			cout << "���¹�ȣ > ";
			cin >> inputAccNum;
			for (int i = 0; i < Account::accCnt; i++) {
				cout << account[i]->GetAccId() << endl;
				if (account[i]->GetAccId() == inputAccNum) {
					account[i]->Show();
				}
			}
			break;
		case 5:
			cout << "�����մϴ�." << endl;
			return 0;
		default:
			cout << "�ٽ� �Է����ּ���." << endl;
		}

		
	}
	return 0;

}