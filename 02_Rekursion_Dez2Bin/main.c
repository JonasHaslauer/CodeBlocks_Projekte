#include <stdio.h>
#include <stdlib.h>

 void dez2bin(int n);

int main()
{
    dez2bin(13);
    return 0;
}

void dez2bin(int n){
    if(n / 2 != 0)
        dez2bin(n/2);

    printf("%d", n%2);
}
