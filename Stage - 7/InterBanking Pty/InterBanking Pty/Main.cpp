#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"BankAccount.h"
#include"CheckingAccount.h"
#include"SavingsAccount.h"
#include"CheckingAccountWithInterest.h"


using namespace std;

const int MAXIMUMACCOUNTS = 10;

//function declarations
int getInt(string);
double getDouble(string);
void createATransferMoney();
void createAccount(CheckingAccount[], SavingsAccount[], CheckingAccountWithInterest[], int*, int*, int*);
void addAccount(CheckingAccountWithInterest[], int);
void addAccount(CheckingAccount[], int);
void addAccount(SavingsAccount[], int);
void viewAccounts(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int, int, int);
void viewDetails(SavingsAccount, int);
void viewDetails(CheckingAccount, int);
void viewDetails(CheckingAccountWithInterest, int);
void writeAccountDetails(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int, int, int, string, string);
void getFileData(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int&, int&, int&, string&, string&);
void displayReport(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int, int, int);


int main()
{
	int num = 1000 + (rand() % 1000);
	int num2 = 1000 + (rand() % 1000);
	int num3 = 1000 + (rand() % 1000);
	int num4 = 1000 + (rand() % 1000);
	int num5 = 1000 + (rand() % 1000);
	cout << num << endl;
	cout << num2 << endl;
	cout << num3 << endl;
	cout << num4 << endl;
	cout << num5 << endl;


	SavingsAccount myAccount(555, 22, "Palawatta Battaramulla",343, 9889.89, 89.98);
	CheckingAccount myacc2(10, 5.435, 555, 22, "Palawatta Battaramulla", 343, 9889.89, 89.98);
	CheckingAccountWithInterest twoinone(12,324,5252,50,"Sri Lanka", 505,49);

	myAccount.display();
	myacc2.display();
	twoinone.display();




	//Declare variables to store the username and password
	string username;
	string password;

	//declare 3 arrays of size 10 for different types of accounts
	SavingsAccount savingsAccounts[10];
	CheckingAccount checkingAccounts[10];
	CheckingAccountWithInterest checkAndInterest[10];

	int numSavingsAccounts = 0;
	int numCheckAccounts = 0;
	int numCheckAndInterestAccounts = 0;


	bool logged = false;


	//check if the file exist 
	ifstream ifile("BankAccounts.txt");
	if (ifile)
	{
		string checkUserName;
		string checkPassword;
		getFileData(savingsAccounts, checkingAccounts, checkAndInterest, numSavingsAccounts, numCheckAccounts, numCheckAndInterestAccounts, username, password);
		do
		{
			cout << "Please enter the username: ";
			cin >> checkUserName;

			cout << "Please enter the password: ";
			cin >> checkPassword;

		} while ((checkUserName.compare(username) != 0 || checkPassword.compare(password) != 0));
	}
	else
	{
		//if not create an userAccount
		cout << "Please enter the username: ";
		getline(cin, username);

		//std::cin.ignore();

		cout << "Please enter the password for the account: ";
		getline(cin, password);



		//at the initial attempt log the user in
		logged = true;
	}

	int userChoice = 0;

	while (userChoice != 5)
	{


		//display the menue 
		cout << "\n\nWelcome to the InterBanking Pty" << endl;

		cout << "1) Create an Account" << endl;
		cout << "2) Transfer Money " << endl;
		cout << "3) View Accounts" << endl;
		cout << "4) Produce Report" << endl;
		cout << "4) Exit the program" << endl;


		userChoice = getInt("Please select your choice: ");

		//validate user choice 
		while (userChoice > 4 || userChoice <= 0)
		{
			userChoice = getInt("Please select your choice: ");
		}

		switch (userChoice)
		{
		case 1:
			createAccount(checkingAccounts, savingsAccounts, checkAndInterest, &numSavingsAccounts, &numCheckAccounts, &numCheckAndInterestAccounts);
			break;
		case 2:
			createATransferMoney();
			break;

		case 3:
			viewAccounts(savingsAccounts, checkingAccounts, checkAndInterest, numSavingsAccounts, numCheckAccounts, numCheckAndInterestAccounts);
			break;

			//break;

		case 4:
			displayReport(savingsAccounts, checkingAccounts, checkAndInterest, numSavingsAccounts, numCheckAccounts, numCheckAndInterestAccounts);
			break;

		default:
			break;
		}

	}

	writeAccountDetails(savingsAccounts, checkingAccounts, checkAndInterest, numSavingsAccounts, numCheckAccounts, numCheckAndInterestAccounts, username, password);

	system("pause");
	return 0;
}

void getFileData(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int& savingsNum, int& checkingNum, int& checkAndInterestNum, string & usename, string & password)
{
	int lineNum = 1;

	int sNum = savingsNum;
	int cNum = checkingNum;
	int ciNum = checkAndInterestNum;

	std::ifstream input("BankAccounts.txt");

	for (std::string line; getline(input, line);)
	{

		if (lineNum == 1)
		{
			usename = line;
		}
		else if (lineNum == 2)
		{
			password = line;
		}
		else
		{
			if (lineNum > 4)
			{
				if (sNum < savingsNum)
				{

					SavingsAccount account();
				}
			}
		}

		lineNum += 1;

	}
}
void viewDetails(CheckingAccountWithInterest accounts[], int withInterestNum)
{
	if (withInterestNum == 0)
	{
		cout << "No Checking Accounts with Interest exist." << endl;
	}
	else
	{
		cout << "\nDisplaying Savings Accounts Details Below.\n\n";
		for (int i = 0; i < withInterestNum; i++)
		{
			accounts[i].display();
			cout << endl;
		}

		cout << endl;
	}
}

void viewDetails(CheckingAccount accounts[], int checkingNum)
{
	if (checkingNum == 0)
	{
		cout << "No Checking Accounts exist." << endl;
	}
	else
	{
		cout << "\nDisplaying Checking Accounts Details Below.\n\n";
		for (int i = 0; i < checkingNum; i++)
		{
			accounts[i].display();
			cout << endl;
		}

		cout << endl;
	}
}

void viewDetails(SavingsAccount accounts[], int savingsNum)
{
	if (savingsNum == 0)
	{
		cout << "No Savings Accounts exist." << endl;
	}
	else
	{
		cout << "\nDisplaying Savings Accounts Details Below.\n\n";
		for (int i = 0; i < savingsNum; i++)
		{
			accounts[i].display();
			cout << endl;
		}

		cout << endl;
	}
}

void viewAccounts(SavingsAccount savingAccounts[], CheckingAccount checkingAccounts[], CheckingAccountWithInterest withInterestAccounts[], int savingsNum, int checkingNum, int checkingWithInterestNum)
{
	int userChoice = 0;

	while (userChoice != 4)
	{


		//display the menue 
		cout << "\n\nPlease Select the account type view details.  \n\n" << endl;

		cout << "1) Savings Accounts" << endl;
		cout << "2) Checking Accounts" << endl;
		cout << "3) Checking Accounts With Interest" << endl;
		cout << "4) Exit to main menu" << endl;

		userChoice = getInt("Please select your choice: ");

		//validate user choice 
		while (userChoice > 4 || userChoice <= 0)
		{
			userChoice = getInt("");
		}

		switch (userChoice)
		{
		case 1:
			viewDetails(savingAccounts, savingsNum);
			break;
		case 2:
			viewDetails(checkingAccounts, checkingNum);
			break;

		case 3:
			viewDetails(withInterestAccounts, checkingWithInterestNum);
			break;

		default:
			break;
		}

	}
}


void createATransferMoney()
{
	cout << "Transfer money " << endl;
}
void createAccount(CheckingAccount checkingAccounts[], SavingsAccount savingsAccounts[], CheckingAccountWithInterest checkAndInterest[], int* numSaving, int* numCheck, int* numcheckAndInterest)
{
	//declare a variable to store the user preferred user choice
	int userChoice = 0;

	//display the menu to the user
	cout << "Please enter the type of the account " << endl;

	if (*numSaving < MAXIMUMACCOUNTS)
	{
		cout << "1) Savigs Account" << endl;
	}
	if (*numCheck < MAXIMUMACCOUNTS)
	{
		cout << "2) Checking Account" << endl;
	}
	if (*numcheckAndInterest < MAXIMUMACCOUNTS)
	{
		cout << "3) Checking Account with Interet " << endl;
	}

	cout << "4) exit " << endl;

	do
	{
		userChoice = getInt("Please enter your choice: ");

	} while ((userChoice > 4 || userChoice < 1));


	//perform the relevent t
	switch (userChoice)
	{
	case 1:
		if (*numSaving < MAXIMUMACCOUNTS)
		{
			addAccount(savingsAccounts, *numSaving);
			*numSaving += 1;
		}
		else
		{
			cout << "Maximum Account limit reached for Savings accounts" << endl;
		}
		break;

	case 2:
		if (*numCheck < MAXIMUMACCOUNTS)
		{
			addAccount(checkingAccounts, *numCheck);
			*numCheck += 1;
		}
		else
		{
			cout << "Maximum Account limit reached for checking accounts" << endl;
		}
		break;

	case 3:
		if (*numcheckAndInterest < MAXIMUMACCOUNTS)
		{
			addAccount(checkAndInterest, *numcheckAndInterest);
			*numcheckAndInterest += 1;
		}
		else
		{
			cout << "Maximum Account limit reached for checking with interest accounts" << endl;
		}
		break;

	default:
		break;
	}




}



void addAccount(CheckingAccountWithInterest accounts[], int index)
{
	//declare variables to hold the user inputs
	int accountNumber = 0;
	double balance;
	int BSB;
	string address;
	int postcode;

	//generate the account number randomly between 1000 9999
	accountNumber = 1000 + (rand() % 1000);

	//promt the user for values
	cout << "\nEnter the account balance: ";
	balance = getDouble("");

	cout << "Enter the BSB number: ";
	BSB = getInt("");

	cout << "Enter the address: ";
	cin >> address;
	std::cin.ignore();

	cout << "Enter the Postcode";
	postcode = getInt("");


	//create an object of the account type
	CheckingAccountWithInterest account(0, 0, accountNumber, BSB, address, postcode, balance);

	// add the account to the relevent index
	accounts[index] = account;

}

void addAccount(CheckingAccount accounts[], int index)
{
	//declare variables to hold the user inputs
	int accountNumber = 0;
	double balance;
	int BSB;
	string address;
	int postcode;

	//generate the account number randomly between 1000 9999
	accountNumber = 1000 + (rand() % 1000);

	//promt the user for values
	cout << "\nEnter the account balance: ";
	balance = getDouble("");

	cout << "Enter the BSB number: ";
	BSB = getInt("");

	cout << "Enter the address: ";
	cin >> address;
	std::cin.ignore();

	cout << "Enter the Postcode";
	postcode = getInt("");


	//create an object of the account type
	CheckingAccount account(0, 0, accountNumber, BSB, address, postcode, balance);

	// add the account to the relevent index
	accounts[index] = account;

}

void addAccount(SavingsAccount accounts[], int index)
{
	//declare variables to hold the user inputs
	int accountNumber = 0;
	double balance;
	int BSB;
	string address;
	int postcode;

	//generate the account number randomly between 1000 9999
	accountNumber = 1000 + (rand() % 1000);

	//promt the user for values
	cout << "\nEnter the account balance: ";
	balance = getDouble("");

	cout << "Enter the BSB number: ";
	BSB = getInt("");

	cout << "Enter the address: ";
	cin >> address;
	std::cin.ignore();

	cout << "Enter the Postcode";
	postcode = getInt("");

	//create an object of the account type
	SavingsAccount account(accountNumber, BSB, address, postcode, balance);

	// add the account to the relevent index
	accounts[index] = account;
}


int getInt(string message)
{
	cout << message;
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

double getDouble(string message)
{
	cout << message;
	std::string line;
	double d;
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
	return d;


	system("pause");

}

void displayReport(SavingsAccount savingAccounts[], CheckingAccount checkingAccounts[], CheckingAccountWithInterest withInterest[], int savingsize, int checkingSize, int withInterestSize)
{


	//write savings accountst to the file

	cout << "........................................Report Begains...............................................\n\n";

	cout << "Savings Accounts: ";
	cout << "Below account Details are in the format of - Account No, Account Balance, BSB No, Branch address and Postcode \n";


	for (int i = 0; i < savingsize; i++)
	{
		cout << savingAccounts[i].getAccountNum() << ", " << savingAccounts[i].getBalance() << ", "  \
			<< savingAccounts[i].getBSB() << ", " << savingAccounts[i].getAddress() << ", " << savingAccounts[i].getPostCode() << endl;
	}

	cout << endl;

	//write checking accounts to the file

	cout << "Checking Accounts: ";
	cout << "Below account Details are in the format of - Account No, Account Balance, BSB No, Branch address, Postcode, Monthly fee and Number of checks allowed per month \n";


	for (int i = 0; i < checkingSize; i++)
	{
		cout << checkingAccounts[i].getAccountNum() << ", " << checkingAccounts[i].getBalance() << ", "  \
			<< checkingAccounts[i].getBSB() << ", " << checkingAccounts[i].getAddress() << ", " << checkingAccounts[i].getPostCode() << ", "
			<< checkingAccounts[i].getMonthlyFee() << ", " << checkingAccounts[i].getChecksPerMonth() << endl;
	}

	cout << endl;

	//write checking accounts with interest to the file

	cout << "Checking Accounts with Interest: ";
	cout << "Below account Details are in the format of - Account No, Account Balance, BSB No, Branch address, Postcode, Monthly fee and Number of checks allowed per month \n";


	for (int i = 0; i < withInterestSize; i++)
	{
		cout << withInterest[i].getAccountNum() << ", " << withInterest[i].getBalance() << ", "  \
			<< withInterest[i].getBSB() << ", " << withInterest[i].getAddress() << ", " << withInterest[i].getPostCode() << ", "
			<< withInterest[i].getMonthlyFee() << ", " << withInterest[i].getChecksPerMonth() << endl;
	}
}

void writeAccountDetails(SavingsAccount savingAccounts[], CheckingAccount checkingAccounts[], CheckingAccountWithInterest withInterest[], int savingsize, int checkingSize, int withInterestSize, string username, string password)
{
	//open the file to write
	ofstream writeFile;
	writeFile.open("BankAccounts.txt");

	//writing the username and the password of the user at the top of the file
	writeFile << username << endl;
	writeFile << password << endl;

	//write savings accountst to the file

	writeFile << "\nSavings Accounts: ";
	writeFile << "Below account Details are in the format of - Account No, Account Balance, BSB No, Branch address and Postcode \n";


	for (int i = 0; i < savingsize; i++)
	{
		writeFile << savingAccounts[i].getAccountNum() << ", " << savingAccounts[i].getBalance() << ", "  \
			<< savingAccounts[i].getBSB() << ", " << savingAccounts[i].getAddress() << ", " << savingAccounts[i].getPostCode() << endl;
	}

	writeFile << endl;

	//write checking accounts to the file

	writeFile << "Checking Accounts: ";
	writeFile << "Below account Details are in the format of - Account No, Account Balance, BSB No, Branch address, Postcode, Monthly fee and Number of checks allowed per month \n";


	for (int i = 0; i < checkingSize; i++)
	{
		writeFile << checkingAccounts[i].getAccountNum() << ", " << checkingAccounts[i].getBalance() << ", "  \
			<< checkingAccounts[i].getBSB() << ", " << checkingAccounts[i].getAddress() << ", " << checkingAccounts[i].getPostCode() << ", "
			<< checkingAccounts[i].getMonthlyFee() << ", " << checkingAccounts[i].getChecksPerMonth() << endl;
	}

	writeFile << endl;

	//write checking accounts with interest to the file

	writeFile << "Checking Accounts with Interest: ";
	writeFile << "Below account Details are in the format of - Account No, Account Balance, BSB No, Branch address, Postcode, Monthly fee and Number of checks allowed per month \n";


	for (int i = 0; i < withInterestSize; i++)
	{
		writeFile << withInterest[i].getAccountNum() << ", " << withInterest[i].getBalance() << ", "  \
			<< withInterest[i].getBSB() << ", " << withInterest[i].getAddress() << ", " << withInterest[i].getPostCode() << ", "
			<< withInterest[i].getMonthlyFee() << ", " << withInterest[i].getChecksPerMonth() << endl;
	}



	//close the file
	writeFile.close();
}

