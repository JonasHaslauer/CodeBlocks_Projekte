// test-const.c
// gcc test-const.c -o test-const.exe

#include <stdio.h>

int main(void){
	const int* const_ptr;   /* Wert auf den gezeigt wird ist const*/
	int* ptr;
	const int const_value = 0;

	printf("Konstante const_value = %i\n", const_value);     /* liefert  0  */
	const_ptr= &const_value;
	ptr = (int *) const_ptr;
	*ptr = 1;
	printf("Konstante const_value = %i\n", const_value);     /* liefert  1  */

	return 0;
}
/* Ausgabe:
Konstante const_value = 0
Konstante const_value = 1
*/