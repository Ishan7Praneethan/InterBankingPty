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

int main()
{
	//create new bankAccount object
	bankAccount userAccount;

	//prompt for username
	cout << "Enter your Name: ";
	cin >> userAccount.userName;

	//prompt for password
	cout << "\nEnter your password: ";
	cin >> userAccount.password;

	//prompt for account number
	cout << "\nEnter your account number: ";
	cin >> userAccount.accountNumber;

	//prompt for account balance
	cout << "\nEnter your current account balance: ";
	cin >> userAccount.accountBalance;


	//display user details
	cout << "\n" << userAccount.userName << " Welcome to InterBanking Pty";
	cout << "\nYour account number: " << userAccount.accountNumber;
	cout << "\nYour current account Balance: $" << userAccount.accountBalance;

	cout << "\nPress any key to continue...";
	_getwch();

}