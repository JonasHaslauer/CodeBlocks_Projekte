#pragma once

#include <iostream>
#include <string>
using namespace std;

class Account{
    private:
        static int nextNumber;

        string owner_;
        int number_;
        double amount_;

    public:
        Account(string name, double d);
        ~Account(){ cout << "Account-Destructor called..." << endl; }

        double getAmount() const {return amount_;}
        void setAmount(double d) {amount_ = d;}

        string toString() const;
};

