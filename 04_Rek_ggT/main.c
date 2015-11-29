#include <stdio.h>
#include <stdlib.h>

int ggt(int a, int b);

int main()
{
    printf("%d", ggt(1005, 507));
    return 0;
}

int ggt(int a, int b){
    if(b == 0){
        return a;
    }else{
        return ggt(b, a % b);
    }

}
