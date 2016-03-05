// a.hofmann dez 2004
//CRoom.cpp

#include "CRoom.h"
#include <string>
#include <iostream>
using namespace std;

void CRoom::moveto( string& strRoom)
{
    if(strRoom == "None")
    {
        cout << "   Es gibt keinen Weg dorthin!" << endl;
        return;
    }

    readRoomInfo(strRoom);
}

// suche den Raum  "<" + aRoom + ">" und lies die RaumInfo
void CRoom::readRoomInfo(string& aRoom)
{
    string strLine = "";
    string strTemp = "";
    string strRoom = "<" + aRoom + ">";


    // an den Dateianfang positionieren
    fin.seekg(ios::beg);
    fin.clear();

    // zeilenweise lesen
    while(getline(fin, strLine, '\n'))
    {

        if(strLine == strRoom)
        {
            getline(fin, strRoomDescription, '*');

            strCurrentRoom = aRoom;
            fin >> strTemp >> strRoomNorth;
            fin >> strTemp >> strRoomEast;
            fin >> strTemp >> strRoomSouth;
            fin >> strTemp >> strRoomWest;
            fin >> strTemp >> testFilename_;

            return;
        }
    }

}

int CRoom::doTest(string testFilename, string username)
{
    // open document
    XMLDocument doc;
    int ret = doc.LoadFile(testFilename.c_str());
    if (ret!=0)
    {
        cerr << "error opening " << testFilename << endl;
        return -1;
    }

    // vars definieren
    XMLElement* proot;
    XMLElement* pquestion;
    XMLElement* pquestiontxt;
    XMLElement* panswertxt;
    XMLElement* ppoint;

    // Get ROOT Element
    proot = doc.FirstChildElement("fragen");
    if(proot)
    {

        // FIRST ... frage
        pquestion = proot->FirstChildElement("frage");
        while (pquestion)
        {
            pquestiontxt= pquestion->FirstChildElement("fragentext");

            panswertxt= pquestion->FirstChildElement("loesungstext");

            ppoint= pquestion->FirstChildElement("punkte");
        }

    }

}


void CRoom::display(void) const
{
    cout << strRoomDescription << endl << endl;
}
