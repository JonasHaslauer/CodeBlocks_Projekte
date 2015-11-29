#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct room{
char name[128];
int temperature; };
typedef struct room TROOM;

void printDurchschnitt(TROOM *r, int len);

int main()
{
    FILE *f;
    char *fname = "room-temp.txt", *a; //Dateipfad
    char buffer[128];
    int lines, i;
    TROOM *rooms;

    f = fopen(fname, "rt");
    if(f == NULL){
        printf("Datei kann nicht gelesen werden.");
    }else{
        fscanf(f, "%d", &lines);
        rooms = (TROOM*) malloc (lines * sizeof(TROOM));
        for(i = 0; i < lines; i++){
            fscanf(f, "%s", buffer);
            a = strtok(buffer, ":");
            strcpy(rooms[i].name, a);
            a = strtok(NULL, ":");
            rooms[i].temperature = atoi(a);
        }
    }

    for(i = 0; i < lines; i++){
        if(rooms[i].temperature > 19){
                printf("Fenster öffnen:%s:%d\n", rooms[i].name, rooms[i].temperature);
        }
    }

    printDurchschnitt(rooms, lines);

    free(rooms);

    fclose(f);

    return 0;
}

void printDurchschnitt(TROOM *r, int len){
    int i;
    double a = 0.0;
    for(i = 0; i < len; i++){
        a += r[i].temperature;
    }
    a /= (double) len;
    printf("Durchschnittstemperatur: %.2lf\n", a);
}
