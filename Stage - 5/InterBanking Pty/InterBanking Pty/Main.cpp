#include<iostream>
#include<string>

using namespace std;

class BankAccount
{
private:
	int accountNumber;
	double accountBalance;
	static const double interestRate;
	int getValidValue(string, int, int);
	double getValidValue(string, double, double);

public:
	void enterAccountData();
	void computeInterest(int);
	void displayAccount();
	int getAccountNumber();
};

const double BankAccount::interestRate = 3;

void BankAccount::displayAccount()
{
	cout << "Account Number : " << accountNumber << endl;
	cout << "Account Balance: " << accountBalance << endl;
	cout << endl;
}

int BankAccount::getAccountNumber()
{
	return accountNumber;
}

void BankAccount::computeInterest(int numYears)
{
	//declare a variable to hold the endbalance of each year and initialize it to the account balance
	double endbalance = accountBalance;

	cout << "Account No: " << accountNumber << endl;

	for (int year = 1; year <= numYears; year++)
	{
		endbalance = endbalance + ((endbalance * interestRate) / 100);
		cout << "Year " << year << "ending balance is " << endbalance << endl;
	}

	cout << endl;
}

void BankAccount::enterAccountData()
{
	//get the account number from the user
	accountNumber = getValidValue("Please enter the account number: ", 1000, 9999);
	//get the account balance from the user
	accountBalance = getValidValue("Please enter the account balance: ", 0.00, 100000.0);
}

int BankAccount::getValidValue(string message, int lower, int upper)
{
	int counter = 0;
	int number;

	do
	{
		cout << message;
		cin >> number;

		counter++;
		if (counter == 1)
		{
			message = "Invalid input - " + message;
		}

	} while (number > upper || number < lower);

	return number;
}

double BankAccount::getValidValue(string message, double lower, double upper)
{
	int counter = 0;
	double number;

	do
	{
		cout << message;
		cin >> number;

		counter++;
		if (counter == 1)
		{
			message = "Invalid input - " + message;
		}

	} while (number > upper || number < lower);

	return number;
}

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

	//disaplay the information abount each bank account

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
			cout << "Please enter the number of years the account NO: " << accounts[g].getAccountNumber() << " will be active: ";
			cin >> years;
		} while ((years > 40) || (years < 0));
		//displayb user the each year ending balance 

		accounts[g].computeInterest(years);
	}

	system("pause");
	return 0;
}