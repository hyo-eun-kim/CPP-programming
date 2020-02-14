#include "Account.h"
#define MAX_ACCOUNT 100

using namespace std;


class AccountHanlder {
private:
	int accNum = 0;
	Account* account[MAX_ACCOUNT];


public:

	int ShowMenu();
	int ShowAccountMenu();
	void MakeNormalAccount();
	void MakeHighCreditAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAccount();

	~AccountHanlder();
};