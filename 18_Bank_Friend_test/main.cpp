// ahofmann 2015
// main.cpp

#include <iostream>
using namespace std;

#include "Bank.h"
#include "Account.h"


int main(){
	Bank *myBank;
	myBank = new Bank("Hofmann unlimited");

	cout << "\n\n"<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " TEST: STATIC members "<<endl;
	cout << "-------------------------------------------------"<<endl;


	myBank->addAccount("Anton Hofmann", 100.0);
	myBank->addAccount("Beta Hofmann", 200.0);
	myBank->addAccount("Gamma Hofmann", 300.0);

	cout << myBank->toString() << endl;


	cout << "\n\n"<<endl;
	cout << ".... delete Account: Anton Hofmann and add Account: Omega Hofmann";
	cout << " Look at the account number!!!"<<endl;

	myBank->delAccount("Anton Hofmann");
	myBank->addAccount("Omega Hofmann", 900.0);

	cout << myBank->toString() << endl;
	cout << endl;


	cout << "\n\n"<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " TEST: FRIEND class "<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " ONLY class bank can create new Account-objects" <<endl;

//	Account k1("Anton Hofmann", 123.0); 	// error, because cons is private

	int accountNr= myBank->addAccount("Anton Hofmann", 100.0);
	myBank->getAccount(accountNr).deposit(9000.0);

	cout << myBank->toString() << endl;
	cout << endl;


	cout << "-------------------------------------------------"<<endl;
	cout << " TEST: Prepare "<<endl;
	cout << "-------------------------------------------------"<<endl;

	cout << "... 1. double d= myBank->getMaxAccount().getAmount(); "<<endl;
	double d = myBank->getMaxAccount().getAmount();
	cout << "...    Maximal amount = " << d << endl <<endl;

	cout << "... 2. double d= myBank->getMaxAccount().getAmount(); "<<endl;
	d= myBank->getStandardDeviation();
	cout << "...    Standard Deviation = " << d << endl << endl;

	cout << "... 3. myBank->delAccount(myBank->getAverageAmount()); "<<endl;
	cout << "...    delete all Account having less then the average amount"<<endl;
	cout << "...    Average Amount= " << myBank->getAverageAmount() << endl<<endl;
//	myBank->delAccount(myBank->getAverageAmount());

	cout << myBank->toString() << endl;
	cout << endl;

/*	d= myBank->getStandardDeviation();
	cout << "Standard Deviation = " << d << endl << endl;
*/
	delete myBank;

	return 0;
}

