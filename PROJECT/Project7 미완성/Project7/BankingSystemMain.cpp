#include "BankingCommonDecl.h"
#include "AccountHandler.h"




int main(void) {

	AccountHanlder handler;
	int choice;
	int subchoice;
	while (true) {
		choice = handler.ShowMenu();
		switch (choice) {
		case MENU::ACCOUNT:
			subchoice = handler.ShowAccountMenu();
			if (subchoice == 1) {
				handler.MakeNormalAccount();
			}
			else if (subchoice == 2) {
				handler.MakeHighCreditAccount();
			}
			else {
				cout << "�߸��� �Է�" << endl;
			}
			break;
		case MENU::DEPOSIT:
			handler.DepositMoney();
			break;
		case MENU::WITHDRAW:
			handler.WithdrawMoney();
			break;
		case MENU::SHOW:
			handler.ShowAccount();
			break;
		case MENU::EXIT:
			cout << "�����մϴ�" << endl << endl;
			return 0;
		default:
			cout << "�ٽ� �Է����ּ���." << endl << endl;
		}
	}
	return 0;
}
