#ifndef CRoom_h
#define CRoom_h CRoom_h

#include <fstream>
#include <string>
#include <vector>
#include "CItem.h"
using namespace std;

class CRoom{
private:
	string strCurrentRoom;				// speichert den Namen des aktuellen Raumes
	string strRoomDescription;			// Raum-Beschreibung (s.u.: endet mit *)
	string strRoomNorth;				// Name des Raumes, der im Norden ist
	string strRoomEast;					// -"-
	string strRoomSouth;				// -"-
	string strRoomWest;					// -"-

	ifstream& fin;						//Merke FileStream zur Datenbasis
	vector<CItem*>* items;
	vector<string> showable;

public:
	CRoom(ifstream& pfin, vector<CItem*>* items): fin(pfin) {this->items = items;}		//Merke FileStream zur Datenbasis

	void moveto(string& aRoom);			//ruft readRoomInfo() auf
	void readRoomInfo(string& aRoom);

	string getCurrentRoom(void)const{ return strCurrentRoom; }
	string getRoomNorth(void)const{ return strRoomNorth; }
	string getRoomSouth(void)const{ return strRoomSouth; }
	string getRoomWest(void)const{ return strRoomWest; }
	string getRoomEast(void)const{ return strRoomEast; }
	vector<string> getShowable(void)const{ return showable; }

	string toString(){ return strRoomDescription; };

	void display(void) const;
	void displayShowable(string showable);
	void displayItems(void);
	//TODO: operator<<()
};
#endif
