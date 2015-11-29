#pragma once

#include <string>
#include <vector>

#include "account.h"

using namespace std;

class Bank{
    private:
        string name_;
        vector<Account*> accounts_;

    public:
        Bank(string name);
        ~Bank();

        void addAccount(Account& account);
        void delAccount(Account& account);

        void charges(double d);
        void addInterest(double d);

        string toString() const;
};
