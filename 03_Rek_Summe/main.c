#include <stdio.h>
#include <stdlib.h>

int summe(int n);

int main()
{
    printf("%d", summe(10));
    return 0;
}

int summe(int n){
    if(n > 0)
        return n + summe(n -1);
    else{
        return 0;
    }
}
