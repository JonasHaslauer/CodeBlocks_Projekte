#ifndef CRoom_h
#define CRoom_h CRoom_h

#include <fstream>
#include <string>
#include <vector>
#include "CItem.h"
#include "CMonster.h"
using namespace std;

class CRoom{
private:
	string strCurrentRoom;				// speichert den Namen des aktuellen Raumes
	string strRoomDescription;			// Raum-Beschreibung (s.u.: endet mit *)
	string strRoomNorth;				// Name des Raumes, der im Norden ist
	string strRoomEast;					// -"-
	string strRoomSouth;				// -"-
	string strRoomWest;					// -"-

	bool monsterInRoom;

	ifstream& fin;						//Merke FileStream zur Datenbasis
	vector<CItem*>* items;
	vector<CMonster*>* monsters;
	vector<string> showable;

public:
	CRoom(ifstream& pfin, vector<CItem*>* items, vector<CMonster*>* monsters): fin(pfin) {this->items = items; this->monsters = monsters;}
	void moveto(string& aRoom);			//ruft readRoomInfo() auf
	void readRoomInfo(string& aRoom);

	string getCurrentRoom(void)const{ return strCurrentRoom; }
	string getRoomNorth(void)const{ return strRoomNorth; }
	string getRoomSouth(void)const{ return strRoomSouth; }
	string getRoomWest(void)const{ return strRoomWest; }
	string getRoomEast(void)const{ return strRoomEast; }
	vector<string> getShowable(void)const{ return showable; }
	bool hasMonster(){ return monsterInRoom; }

	string toString(){ return strRoomDescription; };


    int findMonster(string name, string room);
    int addMonster(string room, string monsterName);
	void display(void) const;
	void displayShowable(string showable);
	void displayItems(void);
	//TODO: operator<<()
};
#endif
