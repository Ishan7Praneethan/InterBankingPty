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

//Function signatures
double getBalance(string message);
double getInterest(string message);
void writeAccountDetails(bankAccount accounts[], int arraySize);
void displayAccount(bankAccount account);
bankAccount enterAccountData(int);
void computeInterest(bankAccount account);



//creating a constant to hold number of user accounts
int const NumAccount = 10;


int main()
{

	//create new bankAccount objects
	bankAccount userAccount[NumAccount];

	//creating a variable to hold account numbers
	int accNum;

	//create an variable to track number of objects created
	int numOfObj = 0;

	//get user input for each number of accounts
	for (int i = 0; i < NumAccount; i++)
	{

		//get the account number
		do
		{
			cout << "Please enter the Account Number " + to_string(i + 1) + " : ";
			cin >> accNum;

			cin.ignore();

		} while ((accNum != 0) && (accNum > 9999 || accNum < 1000));

		//only continue if the user wish to
		if (accNum == 0)
		{
			break;
		}

		//get the details to the array
		userAccount[i] = enterAccountData(accNum);
		numOfObj++;

	}

	//display the details of each account
	for (int i = 0; i < numOfObj; i++)
	{
		displayAccount(userAccount[i]);
		computeInterest(userAccount[i]);
	}


	//Transferring Money
	//declaring a variable to hold money to be transferred from account 1 to account 2;
	double transferAmount;
	int accNum1, accNum2;



	//prompt user to get transfer amount
	cout << "\n\nEnter the Account Number to Transfer Money From : ";
	cin >> accNum1;
	cout << "Enter the Account Number to Transfer Money To : ";
	cin >> accNum2;
	cout << "Enter the Amount to be transfered from " + to_string(userAccount[accNum1 - 1].accountNumber) + " : ";
	cin >> transferAmount;


	//validate the transaction
	if (userAccount[accNum1 - 1].accountBalance > transferAmount)
	{
		if ((userAccount[accNum1 - 1].accountBalance - transferAmount) < 10)
		{
			cout << "\nWarning ! : Account No-" + to_string(userAccount[accNum1 - 1].accountNumber) + " balance is below $10.00 " << endl;
		}
		if ((userAccount[accNum2 - 1].accountBalance + transferAmount) > 100000)
		{
			cout << "\nWarning ! : Account No-" + to_string(userAccount[accNum2 - 1].accountNumber) + " balance is higher than amount fedarally insured" << endl;
		}

		// complete the transaction
		userAccount[accNum1 - 1].accountBalance -= transferAmount;
		userAccount[accNum2 - 1].accountBalance += transferAmount;

	}
	else
	{
		cout << "\nTransaction Unsuccessful :- Insufficient credit " << endl;
	}

	//finally show the account status after Transactions
	cout << "\nUpdated Account details\n" << endl;
	for (int i = 0; i < numOfObj; i++)
	{
		displayAccount(userAccount[i]);
	}

	//write account details to a file
	writeAccountDetails(userAccount, numOfObj);

	cout << "\nPress any key to Exit...";
	_getwch();

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
	double const min = 0.01;
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


void displayAccount(bankAccount account)
{
	cout << endl;
	cout << "Account Number: " << account.accountNumber << endl;
	cout << "Customer Name: " << account.userName << endl;
	cout << "Account Balance: " << account.accountBalance << endl;
	cout << "Interest Rate: " << account.interestRate << endl;
	cout << endl;

}

void writeAccountDetails(bankAccount accounts[], int arraySize)
{
	//open the file to write
	ofstream writeFile;
	writeFile.open("InterBankingPty-CustomerAccounts.txt");

	writeFile << "Below account Details are in the format of - Account No, User Name, Interest Rate, Account Balance. \n\n";

	for (int i = 0; i < arraySize; i++)
	{
		writeFile << accounts[i].accountNumber << ", " << accounts[i].userName << ", " << accounts[i].interestRate << ", " \
			<< accounts[i].accountBalance << endl;
	}

	//close the file
	writeFile.close();
}

bankAccount enterAccountData(int accountNumber)
{
	//declare a local bank account objcts 
	bankAccount account;

	//get the details from the user 
	cout << "Please enter the customer name: ";
	getline(cin, account.userName);

	cout << "Please enter the password for the user: ";
	getline(cin, account.password);

	account.accountNumber = accountNumber;
	account.accountBalance = getBalance("Please Enter the Balance in $: ");
	account.interestRate = getInterest("Please enter the Interest Rate: ");

	return account;
}

void computeInterest(bankAccount account)
{
	//get the number of years account will earn interest from the user
	//declare a variable to hold the number of years and ending balance for the year
	int years;
	double endBalance = account.accountBalance;
	cout << "Please enter the number of years the account will earn interest: ";
	cin >> years;

	//validate user input of year 
	while (years < 1)
	{
		cout << "Number of years can't be 0 or negative - Please provide a valid input: ";
		cin >> years;
	}

	for (int i = 0; i < years; i++)
	{
		//calculate the end balance
		endBalance += (endBalance * account.interestRate) / 100;
		cout << "year " << to_string(i + 1) << " end balance is " << endBalance << endl;

	}
}





