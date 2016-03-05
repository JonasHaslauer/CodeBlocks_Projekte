#include "CMonster.h"

CMonster::CMonster(string name, int hp, int dmg, string atk, string room){
    this->name = name;
    health = hp;
    damage = dmg;
    attack = atk;
    this->room = room;
}
