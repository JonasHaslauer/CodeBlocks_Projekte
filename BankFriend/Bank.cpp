
//Bank.cpp


#include <string>
#include <iostream>
#include <sstream>
#include "Bank.h"
#include "Account.h"

using namespace std;

Bank::Bank(string name)
{
	name_ = name;
}

Bank::~Bank(){
    for(int i = 0; i < accounts_.size(); i++){
        delete accounts_[i];
    }
}

void Bank::delAccount(string owner){
    vector<Account*>::iterator it;
	for (it = accounts_.begin(); it != accounts_.end(); it++)
	{
		if (owner==(*it)->owner_)
		{
		    delete (*it);
			accounts_.erase(it);
			return;
		}
	}
}
int Bank::addAccount (string owner, double d){
    Account* acc = new Account(owner, d);
    accounts_.push_back(acc);
    return acc->number_;
}

Account& Bank::getAccount(int nr){
    vector<Account*>::iterator it;
	for (it = accounts_.begin(); it != accounts_.end(); it++)
	{
		if (nr==(*it)->number_)
		{
			return **it;
		}
	}
}

void Bank::charges(double d)
{
	vector<Account*>::iterator it;
	for (it = accounts_.begin(); it != accounts_.end(); it++)
	{
		double newValue = (*it)->getAmount() - d;
		(*it)->setAmount(newValue);

	}
}

void Bank::delAccount(Account& account)
{
	vector<Account*>::iterator it;
	for (it = accounts_.begin(); it != accounts_.end(); it++)
	{
		if (*it == & account)
		{
			accounts_.erase(it);
			return;
		}
	}
}

void Bank::addInterest(double d)
{
	vector<Account*>::iterator it;
	for (it = accounts_.begin(); it != accounts_.end(); it++)
	{
		double newValue = (*it)->getAmount() + d;
		(*it)->setAmount(newValue);

	}
}

void Bank::addAccount(Account& account)
{
	accounts_.push_back(&account);	//!!!!!!!!!!!!!!!!!
}

string Bank::toString() const
{
	ostringstream os;
	vector<Account*>::const_iterator it;

	os << "\nBANK: " << name_ << endl;

	/*
	for (int i = 0; i < accounts_.size(); i++)
		os << accounts_[i]->toString() << endl;

*/
	for (it = accounts_.begin(); it != accounts_.end(); it++)
		os << (*it)->toString() << endl;


	/*for (auto paccount : accounts_){
		os << paccount->toString() << endl;
	}*/

	return os.str();
}


