#pragma once
#include "SavingsAccount.h"
#include "CheckingAccount.h"

class CheckingAccountWithInterest :
	public SavingsAccount, public CheckingAccount
{
protected:

public:
	CheckingAccountWithInterest();
	CheckingAccountWithInterest(int checkPerMonths, double monthlyFee, int accountNumber, int BSB, std::string address, int postcode, double accountBalance, double interestRate = 0.02);
	~CheckingAccountWithInterest();
	void display();

	void setBalance(double);
	void setAccountNum(int);
	void setBSB(int);
	void setAddress(std::string);
	void setInterest(double);

	double getMonthlyFee();
	double getBalance();
	int getAccountNum();
	int getBSB();
	std::string getAddress();
	double getInterest();
	int getPostCode();

};


