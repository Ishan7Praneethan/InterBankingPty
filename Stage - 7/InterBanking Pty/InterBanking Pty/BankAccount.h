#pragma once
#include"BankBranch.h"

class BankAccount
{
protected:
	int accountNumber;
	double accountBalance;
	double interestRate = 0.03;
	BankBranch homeBranch;

public:
	BankAccount(int, int, std::string, int, double = 0, double = 0.0);
	int getInt(std::string);
	void display();
	BankAccount();
	void setBalance(double);
	void setAccountNum(int);
	void setBSB(int);
	void setAddress(std::string);
	void setInterest(double);

	double getBalance();
	int getAccountNum();
	int getBSB();
	std::string getAddress();
	double getInterest();
	int getPostCode();

	~BankAccount();
};

