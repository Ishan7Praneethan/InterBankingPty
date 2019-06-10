#pragma once
#include<string>

class BankBranch
{

protected:
	int BSB;
	std::string address;
	int postcode;

public:
	BankBranch(int, std::string, int);
	BankBranch();
	int getBsb();
	std::string getAddress();
	int getPostCode();
	void setData(int, std::string, int);

	void setBSB(int);
	void setAddress(std::string);
	void setPostcode(int);

};

