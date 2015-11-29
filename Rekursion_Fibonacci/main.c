#include <stdio.h>

// F- Prototyp
int fib(int n);

// F-Aufrufen
int main(){
    int zahl,i;

    printf("\nFibonacci-Folge (rekursiv)");
    do{
        printf("\nBitte eine pos. Zahl: ");
        scanf("%i", &zahl);
    }while (zahl < 0);

    for (i=0; i<= zahl; i++){
        printf("%i,", fib(i));  // Aufruf der Funktion fib()
    }

    putchar('\n');
    return 0;
}


int fib(int n){
	if (n == 0){
		return 0;
	}
	else if (n == 1){
		return 1;
	}
	else{
		return (fib(n - 1) + fib(n - 2));
	}
}
