#ifndef CItem_h
#define CItem_h

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class CItem {
private:
    string name;
    string room;
    bool owned;
    int value;

public:
    CItem(string room, string name, int value, bool owned);
    ~CItem();

    string getName(){ return name; }
    string getRoom(){ return room; }
    int getValue(){ return value; }
    bool isOwned(){ return owned; }
    void setOwned(bool owned){ this->owned = owned; }

    bool isItemInVector(vector<CItem*>* items, string name, string room);


};

#endif // CITEM_H
