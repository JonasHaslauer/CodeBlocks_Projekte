// test-const-ptr.c
// gcc test-const-ptr.c -o test-const-ptr.exe

#include <stdio.h>

int main(void){
	char* mybuf= "12345";
	char* yourbuf= "abcde";
	
	char* const const_buf_ptr = mybuf;     /* konstanter Zeiger */

	*const_buf_ptr = 'a';

	const_buf_ptr++;                       /* !!! Fehler !!! */         
	const_buf_ptr = yourbuf;               /* !!! Fehler !!! */

	return 0;
}
/* Ausgabe:
test-const-ptr.c: In function ‘main’:
test-const-ptr.c:14: error: increment of read-only variable ‘const_buf_ptr’
test-const-ptr.c:15: error: assignment of read-only variable ‘const_buf_ptr’
*/