#include "CheckingAccount.h"
#include <iostream>


CheckingAccount::CheckingAccount(int checkPerMonths, double monthlyFee, int accountNumber, int BSB, std::string address, int postcode, double accountBalance, double interestRate) :BankAccount(accountNumber, BSB, address, postcode, accountBalance, interestRate)
{
	/*get user input from here .....*/
	std::cout << "Enter the monthly fee: ";
	std::cin >> this->monthlyFee;

	std::cout << "Enter the number of checks allowed per month: ";
	std::cin >> this->checksAllowedPerMonth;

	//this->checksAllowedPerMonth = checkPerMonths;
	//this->monthlyFee = monthlyFee;
}

CheckingAccount::CheckingAccount()
{

}

double CheckingAccount::getMonthlyFee()
{
	return monthlyFee;
}

int CheckingAccount::getChecksPerMonth()
{
	return checksAllowedPerMonth;
}

void CheckingAccount::display()
{
	BankAccount::display();
	std::cout << "Checks Allowed per month: " << checksAllowedPerMonth << std::endl;
	std::cout << "Monthly fee: " << monthlyFee << std::endl;
}

void CheckingAccount::SetCheckingAccount(int accountNumber, int BSB, std::string address, int postcode, double accountBalance, double interestRate)
{
	this->accountNumber = accountNumber;
	this->accountBalance = accountBalance;
	this->interestRate = interestRate;
	this->homeBranch.setData(BSB, address, postcode);
}


