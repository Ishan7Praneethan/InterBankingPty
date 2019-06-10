#include "BankAccount.h"
#include <iostream>
#include <string>



BankAccount::BankAccount(int accountNumber, int BSB, std::string address, int postcode, double accountBalance, double interestRate) :homeBranch(BSB, address, postcode)
{
	this->accountNumber = accountNumber;
	this->accountBalance = accountBalance;
	this->interestRate = interestRate;
}
int BankAccount::getPostCode()
{
	return homeBranch.getPostCode();
}

int BankAccount::getAccountNum()
{
	return accountNumber;
}
int BankAccount::getBSB()
{
	return homeBranch.getBsb();
}
std::string BankAccount::getAddress()
{
	return homeBranch.getAddress();
}
double BankAccount::getInterest()
{
	return interestRate;
}

double BankAccount::getBalance()
{
	return accountBalance;
}

void BankAccount::setBalance(double accountBalance)
{
	this->accountBalance = accountBalance;
}

void BankAccount::setAccountNum(int accountNumber)
{
	this->accountNumber = accountNumber;
}

void BankAccount::setBSB(int BSB)
{
	homeBranch.setBSB(BSB);
}
void BankAccount::setAddress(std::string address)
{
	homeBranch.setAddress(address);
}
void BankAccount::setInterest(double interestRate)
{
	this->interestRate = interestRate;
}

BankAccount::BankAccount()
{

}


BankAccount::~BankAccount()
{
}


void BankAccount::display()
{
	std::cout << "Account No: " << accountNumber << std::endl;
	std::cout << "Balance: " << accountBalance << std::endl;
	std::cout << "Interest Rate: " << interestRate << std::endl;
	std::cout << "BSB: " << homeBranch.getBsb() << std::endl;
	std::cout << "Branch address: " << homeBranch.getAddress() << std::endl;
	std::cout << "Post Code: " << homeBranch.getPostCode() << std::endl;
}
/*
int BankAccount::getInt(std::string message)
{
	//std::cout << message;
	std::string line;
	int d;
	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> d)
		{
			if (ss.eof())
			{   // Success
				break;
			}
		}
		std::cout << "Error!" << " " << message;
	}
	return d;;
}
*/