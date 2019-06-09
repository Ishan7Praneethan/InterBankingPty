#pragma once
#include<string>

class BankAccount
{
private:
	int accountNumber;
	double accountBalance;
	static const double interestRate;
	int getValidValue(std::string, int, int);
	double getValidValue(std::string, double, double);

public:
	void enterAccountData();
	void computeInterest(int);
	void displayAccount();
	int getAccountNumber();
	void setAccountBalance(double);
	double getBalance();
};