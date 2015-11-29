// test-fraction.cpp

#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{

    Fraction a(3.0, 2.0);
    cout << "a = " << a.toString() << endl;


    Fraction b(a); //Fraction b = a;
    cout << "b = " << b.toString() << endl;


    Fraction c;
    cout << "c = " << c.toString() << endl;


    c = a.mul(b);
    cout << "c = " << c.toString() << endl;


    return 0;
}
