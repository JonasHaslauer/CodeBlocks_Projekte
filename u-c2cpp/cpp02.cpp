//cpp02.cpp
///////////
// A program without function prototypes
// Note: This will not compile
#include <iostream>
using namespace std;

void display (const char *s);

int main()
{
    display("Hello, world\n");

    return 0;
}

void display (const char *s)       //void display (s)
{
    //char *s;    //Error: old style doesn't work
    cout << s;                   //{
}                            //  cout << s;

//}
