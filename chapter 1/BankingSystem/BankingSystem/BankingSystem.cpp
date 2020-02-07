#include <iostream>
#include "Banking.h"

int main(void) {

	while (1) {
		int button = ShowMenu();
		switch (button)
		{
		case 1:
			OpenAccount();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdraw();
			break;
		case 4:
			ShowMoney();
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}

	return 0;
}