#pragma once
#pragma once

#include"BankAccount.h";

class Transaction
{
private:
	int amount;
	int account1ID;
	int account2ID;
	double account1StartBalance;
	double account2StartBalance;
	void rollBack(double, double, BankAccount, BankAccount);


public:
	Transaction(BankAccount, BankAccount, double, int, int, BankAccount[]);
};

