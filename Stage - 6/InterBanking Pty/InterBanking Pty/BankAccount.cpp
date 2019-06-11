#include "BankAccount.h"
#include<iostream>
#include<string>

const double BankAccount::interestRate = 3;

double BankAccount::getBalance()
{
	return accountBalance;
}

void BankAccount::setAccountBalance(double ammount)
{
	accountBalance = ammount;
}

void BankAccount::displayAccount()
{

	std::cout << "Account Number : " << accountNumber << std::endl;
	std::cout << "Account Balance: $" << accountBalance << std::endl;
	std::cout << std::endl;
}

int BankAccount::getAccountNumber()
{
	return accountNumber;
}

#include<iostream>
void BankAccount::computeInterest(int numYears)
{
	//declare a variable to hold the endbalance of each year and initialize it to the account balance
	double endbalance = accountBalance;

	std::cout << "\nAccount No: " << accountNumber << std::endl;
	std::cout << "----------------" << std::endl;
	for (int year = 1; year <= numYears; year++)
	{
		endbalance = endbalance + ((endbalance * interestRate) / 100);
		std::cout << "Year - " << year << " the Ending balance is $" << endbalance << std::endl;
	}

	std::cout << std::endl;
}

void BankAccount::enterAccountData()
{
	//get the account number from the user
	accountNumber = getValidValue("\nEnter the account number: ", 1000, 9999);
	//get the account balance from the user
	accountBalance = getValidValue("Enter the account balance: $", 0.00, 100000.0);
}

int BankAccount::getValidValue(std::string message, int lower, int upper)
{
	int counter = 0;
	int number;

	do
	{
		std::cout << message;
		std::cin >> number;

		counter++;
		if (counter == 1)
		{
			message = "*Invalid input*\n" + message;
		}

	} while (number > upper || number < lower);

	return number;
}

double BankAccount::getValidValue(std::string message, double lower, double upper)
{
	int counter = 0;
	double number;

	do
	{
		std::cout << message;
		std::cin >> number;

		counter++;
		if (counter == 1)
		{
			message = "*Invalid input*\n " + message;
		}

	} while (number > upper || number < lower);

	return number;
}
