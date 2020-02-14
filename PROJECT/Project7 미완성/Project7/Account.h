#pragma once

class Account {
private:
	const int accountNum;
	char* name;
protected:
	int balance;

public:
	Account(int accountNum, char* name, int balance);
	Account(const Account& account);

	int GetAccountNum() const;
	virtual bool DepositMoney(int money) {
		cout << "[��   ��]" << endl;
		if (money > 0) {
			cout << "�ԱݿϷ�(step1)" << endl;
			balance += money;
			return true;
		}
		else {
			cout << "�߸��� �Ա��Դϴ�." << endl << endl;
			return false;
		}
	}
	void WithdrawMoney(int money);
	virtual void ShowAllAccInfo() const {
		cout << endl;
		cout << "����ID: " << accountNum << endl;
		cout << "��  ��: " << name << endl;
		cout << "��  ��: " << balance << endl;
	}


	~Account();
};
