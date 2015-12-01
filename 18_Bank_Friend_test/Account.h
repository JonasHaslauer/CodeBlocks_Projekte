
//Account.h

#pragma once

#include <iostream>
#include <string>
using namespace std;

class Account{
    friend class Bank;
private:
	static int nextNumber; //Membervariable der Klasse

	string owner_;
	int number_;
	double amount_;

	Account(string name, double d);

public:

    ~Account();

	string toString() const;

	double getAmount() const
	{
		return amount_;
	}

	int getNumber() const{
        return number_;
	}

	void setAmount(double d)
	{
		amount_ = d;
	}

	void deposit(double d){setAmount(getAmount()+d);}

};

