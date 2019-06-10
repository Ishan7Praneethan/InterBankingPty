#include "BankBranch.h"

BankBranch::BankBranch()
{

}

BankBranch::BankBranch(int BSB, std::string address, int postcode)
{
	this->BSB = BSB;
	this->address = address;
	this->postcode = postcode;
}

void BankBranch::setData(int BSB, std::string address, int postcode)
{
	this->BSB = BSB;
	this->address = address;
	this->postcode = postcode;
}

void BankBranch::setPostcode(int postcode)
{
	this->postcode = postcode;
}

void BankBranch::setBSB(int BSB)
{
	this->BSB = BSB;
}

void BankBranch::setAddress(std::string address)
{
	this->address = address;
}

int BankBranch::getBsb()
{
	return BSB;
}
std::string BankBranch::getAddress()
{
	return address;
}

int BankBranch::getPostCode()
{
	return postcode;
}

