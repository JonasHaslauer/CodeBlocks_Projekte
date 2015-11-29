#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle a(5, 3);   // length, width
	Rectangle b(a);
	Rectangle c;

	c = a.getArea(b);	// length*width

	cout << "c= " << c.toString() << endl;
}
