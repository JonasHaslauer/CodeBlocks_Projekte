//CRoom.h
//a.hofmann dez. 2004

#ifndef CRoom_h
#define CRoom_h CRoom_h

#include "Question.h"
#include "demo_adventuregame_fragen_tinyxml/tinyxml2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace tinyxml2;
using namespace std;

class CRoom{
private:
	string strCurrentRoom;				// speichert den Namen des aktuellen Raumes
	string strRoomDescription;			// Raum-Beschreibung (s.u.: endet mit *)
	string strRoomNorth;				// Name des Raumes, der im Norden ist
	string strRoomEast;					// -"-
	string strRoomSouth;				// -"-
	string strRoomWest;					// -"-

	vector<Question*> questions_;
	string testFilename_;

	ifstream& fin;						//Merke FileStream zur Datenbasis
public:
	CRoom(ifstream& pfin): fin(pfin) {}		//Merke FileStream zur Datenbasis

	void moveto(string& aRoom);			//ruft readRoomInfo() auf
	void readRoomInfo(string& aRoom);

	string getCurrentRoom(void)const{ return strCurrentRoom; }
	string getRoomNorth(void)const{ return strRoomNorth; }
	string getRoomSouth(void)const{ return strRoomSouth; }
	string getRoomWest(void)const{ return strRoomWest; }
	string getRoomEast(void)const{ return strRoomEast; }

    string getTestFilename(void)const{ return testFilename_; }

    int doTest(string testFilename, string username);

	string toString(){ return strRoomDescription; };

	void display(void) const;
	//TODO: operator<<()
};
#endif
