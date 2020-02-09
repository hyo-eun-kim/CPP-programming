#pragma once



class Account {
private:
	int accountNum;
	char* name;
	int money;

public:
	Account();
	~Account();

	void openAccount();
	
	char* GetName() const;
	int GetMoney() const;
	int GetAccountNum() const;

	bool deposit();
	bool withdraw();
	void show() const;
};
