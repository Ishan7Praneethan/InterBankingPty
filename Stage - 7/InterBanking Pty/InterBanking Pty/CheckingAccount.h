#pragma once
#include "BankAccount.h"
class CheckingAccount :
	public BankAccount

{

protected:
	double monthlyFee;
	int checksAllowedPerMonth;
public:
	CheckingAccount();
	CheckingAccount(int, double, int, int, std::string, int, double = 0, double = 0.03);
	void SetCheckingAccount(int, int, std::string, int, double, double);
	void display();
	int getChecksPerMonth();
	double getMonthlyFee();


};

