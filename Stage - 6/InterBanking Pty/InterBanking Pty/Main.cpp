#include<iostream>
#include"BankAccount.h";
#include"Transaction.h";


#include<string>

using namespace std;

int main()
{
	//declare an array to hold 10 bank accounts
	BankAccount accounts[10];
	int i = 0;
	char userChoice;
	do
	{
		BankAccount account;
		account.enterAccountData();

		//add it to the array of accounts and then increment the i value
		accounts[i++] = account;

		//ask if user wish to add anumore accounts
		if (i < 10)
		{
			cout << "Would you like to add another account ? (y - Yes | any other character - No) : ";
			cin >> userChoice;
		}

	} while ((userChoice == 'y' || userChoice == 'Y') && i < 10);

	// keep a blank line
	cout << endl;

	//disaplay the information about each bank account

	for (int j = 0; j < i; j++)
	{
		BankAccount account;
		account = accounts[j];
		account.displayAccount();
	}

	//declare variable to hold the number of years the account will be active
	int years = 0;

	//computingh results for each year for each account
	for (int g = 0; g < i; g++)
	{
		do
		{
			cout << "Please enter the number of years the account No: " << accounts[g].getAccountNumber() << " will be active: ";
			cin >> years;
		} while ((years > 40) || (years < 0));
		//displayb user the each year ending balance 

		accounts[g].computeInterest(years);
	}

	// do a transaction 
	//get the withdraw account number

	int withIndex;
	int depoIndex;
	int wacoount;
	int daccount;
	double ammount;

	BankAccount withdrawAccount;
	BankAccount depositAccount;


	cout << "Please Enter the Withdrawal account number: ";
	cin >> wacoount;

	cout << "Please Enter the deposit account Number: ";
	cin >> daccount;

	cout << "Please enter the amount to be deposited to " << daccount << " : ";
	cin >> ammount;

	for (int accountIndex = 0; accountIndex < i; accountIndex++)
	{
		if (accounts[accountIndex].getAccountNumber() == wacoount)
		{
			withdrawAccount = accounts[accountIndex];
			withIndex = accountIndex;
		}
		if (accounts[accountIndex].getAccountNumber() == daccount)
		{
			depositAccount = accounts[accountIndex];
			depoIndex = accountIndex;
		}
	}

	Transaction::Transaction(withdrawAccount, depositAccount, ammount, withIndex, depoIndex, accounts);

	//disaplay the information abount each bank account

	for (int j = 0; j < i; j++)
	{
		BankAccount account;
		account = accounts[j];
		account.displayAccount();
	}

	system("pause");
	return 0;
}