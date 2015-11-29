#include <stdio.h>
#include <stdlib.h>

int pow(int x, int n);

int main()
{
    printf("%d", pow(2, 8));
    return 0;
}

int pow(int x, int n){
int ret;
    if(n > 0){
        if(n % 2 == 0){
            ret = pow(x, n / 2);
            ret *= ret;
        }else{
            ret = pow(x, n / 2);
            ret *= ret;
            ret *= x;
        }
    }else{
        return 1;
    }
    return ret;
}
