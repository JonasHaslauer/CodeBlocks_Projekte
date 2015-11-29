//
// u_link.cc anton hofmann
// linkage specification
//
#include <iostream.h>
#include <stdlib.h>
#include <string.h>

// Prototype for a C function comp()
.......................................


void main()
{
//-- Array of string pointers to be stored
static char *brothers[]={
"Anton Hofmann",
"Thomas Auer",
"Gerhard Dim",
"Walter Richter",
"Josef Zahn"
};

//-- sort the strings with qsort()
...................................


//-- display the brothers
for (int i=0; i<5; i++)
	cout << '\n' << brothers[i];

}

// --------------- a function compiled with C linkage comp()
.................
..................
