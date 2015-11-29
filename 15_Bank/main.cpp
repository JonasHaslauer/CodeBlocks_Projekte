#include <iostream>
using namespace std;

#include "bank.h"
#include "account.h"

int main() {


    Bank myB("Zinger Unlimited");


	Account a1("Anton Hofmann",1000.0);
	Account a2("Beta Hofmann", 1000.0);
	Account a3("Gamma Hofmann",1000.0);

	myB.addAccount(a1);
	myB.addAccount(a2);
	myB.addAccount(a3);

	cout << "The Bank: BEFORE calculating the charges *********" << endl;
	cout << myB.toString() << endl;

	myB.charges(10.0);
	cout << "The Bank: AFTER calculating the charges *********" << endl;
	cout << myB.toString() << endl;

	myB.addInterest(5.0);
	cout << "The Bank: AFTER adding the interest *********" << endl;
	cout << myB.toString()  << endl;

	myB.delAccount(a3);
	cout << "The Bank: AFTER deleting a3 (Gamma Hofmann) *********" << endl;
	cout << myB.toString() << endl << endl;


}
