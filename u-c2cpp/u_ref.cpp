// u_ref.c anton hofmann
// demo: references

#include <iostream.h>

// call by reference
void swap (struct bigone .....a, struct bigone .......b);


struct bigone {
int telno;
char text[1000];
} bo[2]={
 	{1234, "Anton Hofmann"},
	{9876, "Josef Hofmann"}
	};

//------------------ MAIN
main(int argc, char **argv, char **envp)
{ 


for (int i=0;i<2;i++){
	cout << '\n' << bo[i].telno;
	cout << '\n' << bo[i].text;
}

// -------------------------
swap (.........., ............);

for (i=0;i<2;i++){
	cout << '\n' << bo[i].telno;
	cout << '\n' << bo[i].text;
}
cout << '\n';
}//end-main


void swap (................. a, ................ b)
{
....................
}
