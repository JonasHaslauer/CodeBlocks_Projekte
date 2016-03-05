#ifndef CMonster_h
#define CMonster_h

#include <string>
#include <vector>

using namespace std;

class CMonster{

private:
    int health;
    int damage;
    string attack;
    string room;
    string name;

public:
    CMonster(string name, int hp, int dmg, string atk, string room);
    ~CMonster();

    int getHealth(){ return health; }
    int getDamage(){ return damage; }
    string getAttack(){ return attack; }
    string getRoom(){ return room; }
    string getName(){ return name; }
};

#endif // CMonster_h
