#include "Transaction.h"
#include <iostream>


void Transaction::rollBack(double withdrawBalance, double depositedBalance, BankAccount account1, BankAccount account2)
{
	account1.setAccountBalance(withdrawBalance);
	account2.setAccountBalance(depositedBalance);
}


Transaction::Transaction(BankAccount withdrawAccount, BankAccount depositAccount, double amount, int withindex, int depoindex, BankAccount arra[])
{

	//declare two flag veriables to keep track of the transaction completion
	bool withdrawed = false;
	bool deposited = false;

	Transaction::amount = amount;
	account1ID = withdrawAccount.getAccountNumber();
	account2ID = depositAccount.getAccountNumber();


	//first check if the amount is legal 

	if ((amount > 100000) || (amount < 0))
	{
		std::cout << "Invalid amount ." << std::endl;
		return;
	}

	//withdraw the amount from the 1st accont 
	if ((withdrawAccount.getBalance() - Transaction::amount) >= 0)
	{
		withdrawAccount.setAccountBalance(withdrawAccount.getBalance() - Transaction::amount);
		withdrawed = true;

	}

	if ((depositAccount.getBalance() + amount) <= 100000)
	{
		depositAccount.setAccountBalance(depositAccount.getBalance() + amount);
		deposited = true;
	}

	if ((withdrawed == false) || (deposited == false))
	{
		rollBack(account1StartBalance, account2StartBalance, withdrawAccount, depositAccount);
	}

	arra[withindex] = withdrawAccount;
	arra[depoindex] = depositAccount;


}

