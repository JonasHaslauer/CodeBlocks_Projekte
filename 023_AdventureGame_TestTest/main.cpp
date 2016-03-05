//a.hofmann dez 2004
//main.cpp
//g++ main.cpp Cgame.cpp CRoom.cpp -o main.exe

#include "CGame.h"

int main(){
    CGame meinSpiel("world.txt");

    meinSpiel.start();
}



