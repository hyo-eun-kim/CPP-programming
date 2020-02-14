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
				cout << "�߸��� �Ա��Դϴ�." << endl << endl;
				return false;
			}
		}
	}

	virtual void ShowAllAccInfo() const {
		Account::ShowAllAccInfo();
		cout << "������: " << interestRate << endl;
	}
};
