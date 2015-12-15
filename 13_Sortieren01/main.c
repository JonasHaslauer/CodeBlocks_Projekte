#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

int main()
{
    int test[LENGTH] = {10, 325, 45, 123, 23, 546, 67, 235, 674, 245};
    int i, buffer;
    char finished = 0; //0 = nicht fertig sortiert, 1 = fertig sortiert

    for(i = 0; i < LENGTH; i++){
        printf("%d, ", test[i]);
    }
    printf("\n");

    while(finished == 0){
        finished = 1;                               //es wird davon ausgegangen, dass man fertig mit sortieren ist.
        for(i = 0; i < (LENGTH - 1); i++){          //Length - 1 damit man beim vergleichen nicht über die arraygröße kommt.
            if(test[i] > test[i + 1]){              //Vergleich ob noch etwas vertauscht werden muss, wenn größer/kleiner Zeichen umgedreht wird, sortiert man andersrum
                finished = 0;                       //Wenn etwas vertauscht werden muss, ist man noch nicht fertig
                buffer = test[i];
                test[i] = test[i + 1];
                test[i + 1] = buffer;
            }
        }
    }


    for(i = 0; i < LENGTH; i++){
        printf("%d, ", test[i]);
    }
    printf("\n");

    return 0;
}
