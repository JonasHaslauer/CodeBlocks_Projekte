
//Bank.cpp


#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
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

void Bank::delAccount(Account& account)
{
	vector<Account*>::iterator it;

	for (it = accounts_.begin(); it != accounts_.end(); it++)
	{
		if (*it == &account)
		{
			accounts_.erase(it);
			return;
		}
	}
}

void Bank::delAccount(double reqAmount){
    vector<Account*>::iterator it;

    for(it = accounts_.begin(); it != accounts_.end(); it++){
        if(((*it)->getAmount()) < reqAmount){
            delete *it;
            accounts_.erase(it);
            it--;   //weil accounts_ liste jetzt ein Element weniger hat.
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
		if (nr == (*it)->number_)
		{
			return **it;
		}
	}
}

Account& Bank::getMaxAccount(){
    double currMax = -1.0;

    int currIndex = -1;

    for(int i = 0; i < accounts_.size(); i++){
        if(accounts_[i]->getAmount() > currMax){
            currMax = accounts_[i]->getAmount();
            currIndex = i;
        }
    }
    return *accounts_[currIndex];
}

double Bank::getStandardDeviation(){
    vector<Account*>::iterator it;
    double average = this->getAverageAmount();
    double diff = 0.0;

    if(accounts_.size() > 1){
        for(it = accounts_.begin(); it != accounts_.end(); it++){
            diff = (average - (*it)->getAmount()) * (average - (*it)->getAmount());
        }
        diff /= accounts_.size();
        return sqrt(diff);
    }else{
        return 0;
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

double Bank::getAverageAmount(){
    double ret = 0.0;

    if(accounts_.size() > 1){
        for(int i = 0; i < accounts_.size(); i++){
            ret += accounts_[i]->getAmount();
        }
        ret /= accounts_.size();
    }
    return ret;
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
	accounts_.push_back(&account);
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


