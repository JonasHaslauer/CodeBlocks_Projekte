
//Account.cpp


#include <string>
#include <iostream>
#include <sstream>
#include "Account.h"

using namespace std;


int Account::nextNumber = 0;

Account::Account(string name, double d)
{
	nextNumber++;

	owner_ = name;
	number_ = nextNumber;
	amount_ = d;
}

Account::~Account(){
    cout << "*** destroying account #" << this->number_ << " ***" << endl;
}

string Account::toString() const
{
	ostringstream os;

	os << "... ACCOUNT-amount: " << amount_ << endl;
	os << "... ACCOUNT-number: " << number_ << endl;
	os << "... ACCOUNT-owner: " << owner_ << endl;

	return os.str();
}

