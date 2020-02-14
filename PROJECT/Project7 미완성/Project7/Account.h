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
		cout << "[입   금]" << endl;
		if (money > 0) {
			cout << "입금완료(step1)" << endl;
			balance += money;
			return true;
		}
		else {
			cout << "잘못된 입금입니다." << endl << endl;
			return false;
		}
	}
	void WithdrawMoney(int money);
	virtual void ShowAllAccInfo() const {
		cout << endl;
		cout << "계좌ID: " << accountNum << endl;
		cout << "이  름: " << name << endl;
		cout << "잔  액: " << balance << endl;
	}


	~Account();
};
