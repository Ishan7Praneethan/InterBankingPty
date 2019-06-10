#include "CheckingAccountWithInterest.h"
#include "BankAccount.h"
#include <iostream>

CheckingAccountWithInterest::CheckingAccountWithInterest(int checkPerMonths, double monthlyFee, int accountNumber, int BSB, std::string address, int postcode, double accountBalance, double interestRate) :SavingsAccount(accountNumber, BSB, address, postcode, accountBalance, interestRate), CheckingAccount(checkPerMonths, monthlyFee, accountNumber, BSB, address, postcode, accountBalance, interestRate)
{

}

CheckingAccountWithInterest::CheckingAccountWithInterest()
{

}
double CheckingAccountWithInterest::getMonthlyFee()
{
	return CheckingAccount::getMonthlyFee();
}

int CheckingAccountWithInterest::getPostCode()
{
	return CheckingAccount::getPostCode();
}

int CheckingAccountWithInterest::getAccountNum()
{
	return CheckingAccount::getAccountNum();
}
int CheckingAccountWithInterest::getBSB()
{
	return CheckingAccount::homeBranch.getBsb();
}
std::string CheckingAccountWithInterest::getAddress()
{
	return CheckingAccount::homeBranch.getAddress();
}
double CheckingAccountWithInterest::getInterest()
{
	return CheckingAccount::getInterest();
}

double CheckingAccountWithInterest::getBalance()
{
	return CheckingAccount::getBalance();
}

void CheckingAccountWithInterest::display()
{
	CheckingAccount::display();
}


CheckingAccountWithInterest::~CheckingAccountWithInterest()
{
}
