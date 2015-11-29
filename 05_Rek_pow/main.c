#include <stdio.h>
#include <stdlib.h>

int pow(int x, int n);

int main()
{
    printf("%d", pow(2, 8));
    return 0;
}

int pow(int x, int n){
    if(n > 0)
        return x * pow(x, n - 1);
    else
        return 1;
}
