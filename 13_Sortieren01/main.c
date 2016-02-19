//BUBBLESORT

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

void myBubbleSort(void * a, int size, int dataTypeSize, int (*compar)(const void *, const void *));
int compareInt(const void * a, const void * b);

int main()
{
    int test[LENGTH] = {10, 325, 45, 123, 23, 546, 67, 235, 674, 245};
    int i, buffer;
    char finished = 0; //0 = nicht fertig sortiert, 1 = fertig sortiert

    for(i = 0; i < LENGTH; i++){
        printf("%d, ", test[i]);
    }
    printf("\n");

    /*while(finished == 0){
        finished = 1;                               //es wird davon ausgegangen, dass man fertig mit sortieren ist.
        for(i = 0; i < (LENGTH - 1); i++){          //Length - 1 damit man beim vergleichen nicht über die arraygröße kommt.
            if(test[i] > test[i + 1]){              //Vergleich ob noch etwas vertauscht werden muss, wenn größer/kleiner Zeichen umgedreht wird, sortiert man andersrum
                finished = 0;                       //Wenn etwas vertauscht werden muss, ist man noch nicht fertig
                buffer = test[i];
                test[i] = test[i + 1];
                test[i + 1] = buffer;
            }
        }
    }*/

    myBubbleSort(test, (sizeof(test) / sizeof(test[0])), sizeof(test[0]), compareInt);


    for(i = 0; i < LENGTH; i++){
        printf("%d, ", test[i]);
    }
    printf("\n");

    return 0;
}

void myBubbleSort(void * a, int size, int dataTypeSize, int (*compar)(const void *, const void *)){
    int finished = 0;
    int i;
    void * buffer = malloc(dataTypeSize);
    while(finished == 0){
        finished = 1;
        for(i = 0; i < (size - 1); i++){
            if(((*compar)(a+(i*dataTypeSize), a+(i+1)*dataTypeSize)) > 0){
                finished = 0;
                memcpy(buffer, a+(i*dataTypeSize), dataTypeSize);
                memcpy(a+((i)*dataTypeSize), a+((i+1)*dataTypeSize), dataTypeSize);
                memcpy(a+((i+1)*dataTypeSize), buffer, dataTypeSize);
            }
        }
    }
}

int compareInt(const void * a, const void * b){
    int* ax = (int*) a;
    int* bx = (int*) b;
    return (*ax - *bx);
}
