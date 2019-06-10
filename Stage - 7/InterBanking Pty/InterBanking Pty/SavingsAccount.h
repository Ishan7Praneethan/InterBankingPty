#pragma once
#include "BankAccount.h"


class SavingsAccount :
	public BankAccount

{
public:
	SavingsAccount(int, int, std::string, int, double = 0, double = 0.03);
	SavingsAccount();

	int getPostCode();
};

