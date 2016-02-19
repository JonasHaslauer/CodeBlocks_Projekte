#include "CItem.h"

CItem::CItem(string room, string name, int value, bool owned)
{
    this->name = name;
    this->value = value;
    this->room = room;
    this->owned = owned;
}

bool CItem::isItemInVector(vector<CItem*>* items, string name, string room)
{
    vector<CItem*>::iterator it;
    for(it = items->begin(); it != items->end(); it++)
    {
        if((*it)->getName() == this->name && (*it)->getRoom() == this->room)
        {
            return true;
        }
    }
    return false;
}
