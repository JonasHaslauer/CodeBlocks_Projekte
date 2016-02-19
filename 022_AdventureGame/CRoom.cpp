#include "CRoom.h"
#include <string>
#include <iostream>
using namespace std;

void CRoom::moveto(string& strRoom)
{
    if(strRoom == "None")
    {
        cout << "   There is no way!" << endl;
        return;
    }

    //Hier weil es sonst nicht funktioniert, weiss nicht warum
    fin.seekg(ios::beg);
    fin.clear();

    readRoomInfo(strRoom);
}

void CRoom::readRoomInfo(string& aRoom)
{
    string strLine = "";
    string strTemp = "";
    int itemValue = 0, iTemp;
    string strRoom = "<" + aRoom + ">";
    CItem* tempItem;
    showable.clear();

    fin.seekg(ios::beg);
    fin.clear();

    while(getline(fin, strLine, '\n'))
    {
        cout << strRoom << " == " << strLine << endl;
        if(strLine == strRoom)
        {
            getline(fin, strRoomDescription, '*');

            strCurrentRoom = aRoom;
            fin >> strTemp >> strRoomNorth;
            fin >> strTemp >> strRoomEast;
            fin >> strTemp >> strRoomSouth;
            fin >> strTemp >> strRoomWest;

            //Read <show> entries
            fin >> strTemp >> iTemp;
            for(int i = 0; i < iTemp; i++){
                fin >> strTemp;
                showable.push_back(strTemp);
            }

            //Read <item> entries, add when not added yet
            fin >> strTemp >> iTemp;
            for(int i = 0; i < iTemp; i++)
            {
                fin >> strTemp;
                if(strTemp != "None")
                {
                    fin >> itemValue;
                    tempItem = new CItem(aRoom, strTemp, itemValue, false);

                    if(items->size() > 0)
                    {
                        //If there is no item with same name in the same room registered in the vector, add item
                        if(!tempItem->isItemInVector(items, strTemp, strCurrentRoom)){
                            items->push_back(tempItem);
                        }
                    }
                    //No items registered in vector yet -> add
                    else
                    {
                        items->push_back(tempItem);
                    }
                }
            }

            return;
        }
    }

}



void CRoom::display(void) const
{
    cout << strRoomDescription << endl << endl << "Locations (n, e, s, w): " << strRoomNorth << ", " << strRoomEast << ", " << strRoomSouth << ", " << strRoomWest << endl << endl;
}

void CRoom::displayShowable(string showable){
    string strTag = "<" + strCurrentRoom + "|" + showable + ">";
    string strLine;

    fin.seekg(ios::beg);
    fin.clear();

    while(getline(fin, strLine, '\n'))
    {
        if(strLine == strTag)
        {
            getline(fin, strLine, '*');
            cout << strLine << endl;
            return;
        }
    }
}

void CRoom::displayItems(void)
{
    vector<CItem*>::iterator it;

    for(it = items->begin(); it != items->end(); it++)
    {
        if((*it)->getRoom() == strCurrentRoom)
        {
            if(!(*it)->isOwned())
            {
                cout << (*it)->getName() << " " << (*it)->getValue() << endl;
            }
        }
    }
}
