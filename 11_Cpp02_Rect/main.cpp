#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle a(5, 3);   // length, width
	Rectangle b(a);

	cout << "b: " << endl << b.toString() << endl;
}
