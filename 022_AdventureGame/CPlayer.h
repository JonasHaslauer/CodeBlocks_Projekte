#ifndef CPlayer_h
#define CPlayer_h

#include <string>

using namespace std;

class CPlayer{

private:
    string name;
    int health;
    int damage;

public:
    CPlayer(string name, int hp, int dmg);
    ~CPlayer();

    string getName(){ return name; }
    int getHealth() { return health; }
    int getDamage() { return damage; }

};

#endif
