//BankSystem.cpp

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "Bank.h"
#include "Account.h"

int main()
{
    Bank *myBank;
    myBank = new Bank("Zinger unlimited");

    cout << "-------------------------------------------------" << endl;
    cout << " TEST: STATIC members "<< endl;
    cout << "-------------------------------------------------"<<endl;

    myBank->addAccount("Anton Hofmann", 100.0);
    myBank->addAccount("Beta Hofmann", 200.0);
    myBank->addAccount("Gamma Hofmann",300.0);
    cout << myBank->toString() << endl;

    cout << "--- delete Account: Anton Hofmann and add Account: Omega Hofmann ---";
    cout << endl << "Look at the account number!" << endl;

    myBank->delAccount("Anton Hofmann");
    myBank->addAccount("Omega Hofmann", 900.0);

    cout << myBank->toString() << endl;
    cout << endl;



    cout << "-------------------------------------------------"<<endl;
    cout << " TEST: FRIEND class "<<endl;
    cout << "-------------------------------------------------"<<endl;
    cout << " ONLY class bank can create new Account-objects" <<endl;

    //Account k1("Anton Hofmann", 123.0); 	// error, because cons is private

    int accountNr = myBank->addAccount("Anton Hofmann", 100.0);
    myBank->getAccount(accountNr).deposit(9000.0);

    cout << myBank->toString() << endl;

    delete myBank;


    return 0;

}
