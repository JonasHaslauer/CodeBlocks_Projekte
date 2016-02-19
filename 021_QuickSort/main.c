/*
# AUFGABE: Quicksort-Wikipedia
---
(AB-SORTIEREN-quicksort-wikipedia.md)

## Aufgabe: Quicksort - Wikipedia
Gegeben sei der Pseudocode von quicksort (siehe ANLAGE_quicksort)
1. Erklären/Beschreiben Sie den Algorithmus Quicksort in eigenen Worten.
2. Vergleichen Sie den Aufwand des Algorithmus im Vergleich zum Bubblesort und
verwenden Sie dabei die sogenannte BIG-O Notation.
3. Programmieren Sie ein Test-Programm test-quicksort-wikipedia.c

**Hint: Big O Notation**
* <http://programmierblog.blogspot.co.at/2013/02/einfuhrung-in-die-o-notation-big-o.html>

**Hint: quicksort**
* <https://de.wikipedia.org/wiki/Quicksort>

** test-quicksort-wikipedia.c **
*/

// test-quicksort-wikipedia.c
// --------------------------------------------
#include <stdio.h>

void quicksort(int * arr, int links, int rechts);
int teile(int * arr, int links, int rechts);

int main()
{
    int a[] = {20, 3, 58, 26, 2, 62};
    int i;

    printf("\nUNSORTIERT ...\n");
    for(i=0; i < 6; i++)
        printf("%3i,", a[i]);
    printf("\n");

    quicksort( a, 0, 5);

    printf("\nSORTIERT ...\n");
    for(i=0; i < 6; i++)
        printf("%3i,", a[i]);

    printf("\n");
    return 0;
}

void quicksort(int * a, int links, int rechts)
{
    int teiler;
    if(links < rechts)
    {
        teiler = teile(a, links, rechts);
        quicksort(a, links, teiler - 1);
        quicksort(a, teiler + 1, rechts);
    }
}

int teile(int * a, int links, int rechts)
{
    int i = links;
    int j = rechts - 1;
    int pivot = a[rechts];
    int buffer;

    do
    {
        while(a[i] <= pivot && i < rechts)
        {
            i++;
        }

        while(a[j] >= pivot && j > links)
        {
            j--;
        }

        if(i < j)
        {
            buffer = a[i];
            a[i] = a[j];
            a[j] = buffer;
        }
    }
    while(i < j);

    if(a[i] > pivot){
        buffer = a[rechts];
        a[rechts] = a[i];
        a[i] = buffer;
    }

    return i;
}
