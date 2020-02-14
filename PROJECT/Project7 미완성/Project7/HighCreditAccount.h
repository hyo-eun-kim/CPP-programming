#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int grade;
public:
	HighCreditAccount(int accountNum, char* name, int balance, double rate, int myGrade)
		:NormalAccount(accountNum, name, balance, rate), grade(myGrade) {}

	bool DepositMoney(int money) {

		if (NormalAccount::DepositMoney(money)) {
			double bonusRate[3] = { 0.07, 0.04, 0.02 };
			if (money > 0) {
				balance += (int)(money * bonusRate[grade - 1]);
				return true;
			}
			else {
				cout << "잘못된 입금입니다." << endl << endl;
				return false;
			}
		}
	}


	virtual void ShowAllAccInfo() const {
		NormalAccount::ShowAllAccInfo();
		cout << "등  급: " << grade << endl << endl;
	}
};