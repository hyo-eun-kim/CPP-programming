#include "Account.h"

class NormalAccount : public Account {
private:
	double interestRate;
public:
	NormalAccount(int accountNum, char* name, int balance, double rate)
		:Account(accountNum, name, balance), interestRate(rate) {}

	double GetInterestRate()const {
		return interestRate;
	}

	bool DepositMoney(int money) {
		if (Account::DepositMoney(money)) {
			if (money > 0) {
				balance += (int)((money) * (interestRate / 100));
				return true;
			}
			else {
				cout << "잘못된 입금입니다." << endl << endl;
				return false;
			}
		}
	}

	virtual void ShowAllAccInfo() const {
		Account::ShowAllAccInfo();
		cout << "이자율: " << interestRate << endl;
	}
};
