#include <iostream>
#include <string>

using namespace std;

struct bankAccount
{
	int accountNumber;
	double accountBalance;
	string userName;
	string password;
};

//creating a constant to hold number of user accounts
int const NumAccount = 2;

int getValidAccountNo(string message)
{
	const int max = 9999;
	const int min = 1000;
	int accNum, counter = 0;
	do
	{
		counter++;
		cout << message;
		cin >> accNum;
		if (counter == 1)
		{
			message = "Invalid input! " + message;
		}
	} while ((accNum < min) || (accNum > max));

	return accNum;
}

double getBalance(string message)
{
	double const min = 0.0;
	double const max = 2147483647;
	double balance;
	int counter = 0;

	do
	{
		counter++;
		cout << message;
		cin >> balance;
		if (counter == 1)
		{
			message = "Invalid Input! " + message;
		}

	} while ((balance < min) || (balance > max));
	return balance;
}

void displayInfo(bankAccount accounts[])
{
	cout << "Account Details" << endl;
	cout << "---------------" << endl;
	for (int i = 0; i < NumAccount; i++)
	{
		cout << "Account No: "+ to_string(i + 1) << endl;
		cout << "Account Number: " << accounts[i].accountNumber << endl;
		cout << "Account Balance: " << accounts[i].accountBalance << endl;
		cout << endl;
	}
}

int main()
{

	//create new bankAccount objects
	bankAccount userAccount[NumAccount];

	//get user input for each number of accounts
	for (int i = 0; i < NumAccount; i++)
	{
		userAccount[i].accountNumber = getValidAccountNo("\nEnter the Account Number " + to_string(i + 1) + " : ");

		//check if any of the account numbers are same
		if (i == 1)
		{
			while (userAccount[i - 1].accountNumber == userAccount[i].accountNumber)
			{
				userAccount[i].accountNumber = getValidAccountNo("Please enter an Account Number which is not " + to_string(userAccount[i - 1].accountNumber) + " : ");
			}
		}

		//get valid account balance
		userAccount[i].accountBalance = getBalance("Enter the remaining balance for Account No-" + to_string(userAccount[i].accountNumber) + " in $ : ");
	}

	//Display user informations
	cout << endl;
	displayInfo(userAccount);

	//Transferring Money
	//declaring a variable to hold money to be transferred from account 1 to account 2;
	double transferAmount;

	//prompt user to get transfer amount
	cout << "Enter the amount to be transferred from Acc.No " + to_string(userAccount[0].accountNumber) + " to " + to_string(userAccount[1].accountNumber) + " : ";
	cin >> transferAmount;

	//validate the transaction
	if (userAccount[0].accountBalance > transferAmount)
	{
		if ((userAccount[0].accountBalance - transferAmount) < 10)
		{
			cout << "\nWarning ! : Account No-"+ to_string(userAccount[0].accountNumber) + " balance is below $10.00 " << endl;
		}
		if ((userAccount[1].accountBalance + transferAmount) > 100000)
		{
			cout << "\nWarning ! : Account No-" +to_string(userAccount[1].accountNumber)+ " balance is higher than amount fedarally insured" << endl;
		}

		// complete the transaction
		userAccount[0].accountBalance -= transferAmount;
		userAccount[1].accountBalance += transferAmount;

	}
	else
	{
		cout << "\nTransaction Unsuccessful :- Insufficient credit " << endl;
	}

	//finally show the account status
	cout << "\nUpdated Account details\n" << endl;
	displayInfo(userAccount);

	cout << "\nPress any key to Exit...";
	_getwch();

}



