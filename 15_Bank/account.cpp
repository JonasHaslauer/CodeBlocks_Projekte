#include "account.h"
#include <sstream>

int Account::nextNumber = 0;

Account::Account(string name, double d){
    nextNumber++;

    owner_ = name;
    number_ = nextNumber;
    amount_ = d;
}

Account::~Account(){
    cout << "Account-Destructor called..." << endl;
}

string Account::toString() const{
    ostringstream os;

    os << "... Account-owner" << owner_ << endl;
    os << "... Account-number" << number_ << endl;
    os << "... Account-amount" << amount_ << endl;

    return os.str();
}
