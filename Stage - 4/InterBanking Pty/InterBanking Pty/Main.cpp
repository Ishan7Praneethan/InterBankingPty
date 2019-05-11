#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct bankAccount
{
	int accountNumber;
	double accountBalance;
	string userName;
	string password;
	double interestRate;
};

//creating a constant to hold number of user accounts
int const NumAccount = 2;
//creating constant to hold Month and Year Details
const int YEAR = 2019;
const int MONTH = 5;

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

double getInterest(string message)
{
	double const min = 0.0;
	double const max = 15.0;
	double interest;
	int counter = 0;

	do
	{
		counter++;
		cout << message;
		cin >> interest;
		if (counter == 1)
		{
			message = "Invalid Input! " + message;
		}

	} while ((interest < min) || (interest > max));
	return interest;
}

void displayInfo(bankAccount accounts[])
{
	for (int i = 0; i < NumAccount; i++)
	{
		cout << "Account No: " + to_string(i + 1) + " Details Below" << endl;
		cout << "Account Number: " << accounts[i].accountNumber << endl;
		cout << "Account Balance: " << accounts[i].accountBalance << endl;
		cout << "Annual Interest rate: " << accounts[i].interestRate << endl;
		cout << endl;
	}
}

void writeAccountDetails(bankAccount accounts[], int arraySize)
{
	//open the file to write
	ofstream writeFile;
	writeFile.open("BankAccounts.txt");

	writeFile << "Below account Details are in the format of - Account No, Interest Rate, Account Balance. \n\n";

	for (int i = 0; i < arraySize; i++)
	{
		writeFile << accounts[i].accountNumber << ", " << accounts[i].interestRate << ", " \
			<< accounts[i].accountBalance << endl;
	}

	//close the file
	writeFile.close();
}

int main()
{

	//create new bankAccount objects
	bankAccount userAccount[NumAccount];

	//get user input for each number of accounts
	for (int i = 0; i < NumAccount; i++)
	{
		userAccount[i].accountNumber = getValidAccountNo("Please enter the Account Number " + to_string(i + 1) + " : ");

		//check if any of the account numbers are same
		if (i == 1)
		{
			while (userAccount[i - 1].accountNumber == userAccount[i].accountNumber)
			{
				userAccount[i].accountNumber = getValidAccountNo("Please enter an Account Number which is not equal to " + to_string(userAccount[i - 1].accountNumber) + " : ");
			}
		}

		//get valid account balance
		userAccount[i].accountBalance = getBalance("Enter the account balance for " + to_string(userAccount[i].accountNumber) + " in $ : ");
		userAccount[i].interestRate = getInterest("Enter the Interest rate for " + to_string(userAccount[i].accountNumber) + " in $ : ");
	}

	//Display user informations
	cout << endl;
	displayInfo(userAccount);

	//Transferring Money
	//declaring a variable to hold money to be transferred from account 1 to account 2;
	double transferAmount;

	//prompt user to get transfer amount
	cout << "Please enter the amount to be transferred from " + to_string(userAccount[0].accountNumber) + " to " + to_string(userAccount[1].accountNumber) + " : ";
	cin >> transferAmount;

	//validate the transaction
	if (userAccount[0].accountBalance > transferAmount)
	{
		if ((userAccount[0].accountBalance - transferAmount) < 10)
		{
			cout << "\nWarning ! : first account balance below $10.00" << endl;
		}
		if ((userAccount[1].accountBalance + transferAmount) > 100000)
		{
			cout << "\nWarning ! : Second account balance is higher than amount fedarally insured" << endl;
		}

		// complete the transaction
		userAccount[0].accountBalance -= transferAmount;
		userAccount[1].accountBalance += transferAmount;

	}
	else
	{
		cout << "\nTransaction Denied - Insufficient amount " << endl;
	}

	//finally show the account status
	cout << "\nFinal account statuses goes as below\n" << endl;
	displayInfo(userAccount);

	//automatic deposit and withdrawal amount per month
	//declare variable to hold the amounts
	double monthlyDeposit;
	double monthlyWithdrawal;

	for (int i = 0; i < NumAccount; i++)
	{
		cout << "\nPlease Enter the monthly Deposit Amount for account No. " + to_string(userAccount[i].accountNumber) + ": ";
		cin >> monthlyDeposit;
		cout << "\nPlease Enter the monthly Withdrawal Amount for account No. " + to_string(userAccount[i].accountNumber) + ": ";
		cin >> monthlyWithdrawal;

		double endingBalance = userAccount[i].accountBalance + (((userAccount[i].accountBalance * userAccount[i].interestRate) / 100) / 12) + monthlyDeposit - monthlyWithdrawal;



		cout << "\n" << YEAR << "/" << MONTH << " Starting balance is " << userAccount[i].accountBalance << \
			" and " << YEAR << "/" << MONTH << " ending balance is " << endingBalance << endl;

		userAccount[i].accountBalance = endingBalance;

	}

	//write account details to a file
	writeAccountDetails(userAccount, NumAccount);

	cout << "\nPress any key to Exit...";
	_getwch();

}



