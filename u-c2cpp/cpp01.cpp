//cpp01.cpp
///////////
#include <iostream>

using namespace std;

int main()
{

    cout << "Hello, world\n";

    int amount = 123;
    cout << amount << endl;

    cout << "The value of amount is " << amount << '.' << endl;

//fromatted ouatput
    cout << dec << amount << ' ';
    cout << oct << amount << ' ';
    cout << hex << amount << endl;

//standard error stream
    cerr << "the standard error stream \"cerr\"" << endl;

//standard input stream
    char name[20];
    cout << "Enter your name ...\n";
    cin >> name;
    cout << "the name you entered was " << name << endl;
    return 0;

