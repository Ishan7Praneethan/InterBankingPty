#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int accountNumber, int BSB, std::string address, int postcode, double accountBalance, double interestRate) :BankAccount(accountNumber, BSB, address, postcode, accountBalance, interestRate)
{

}

SavingsAccount::SavingsAccount()
{

}

int SavingsAccount::getPostCode()
{
	return BankAccount::getPostCode();
}
