//a.hofmann dez 2004
//CGame.cpp

#include "CGame.h"
#include <iostream>
#include <string>
#include <cstdlib>  // exit()

using namespace std;


CGame::CGame(const char* pFilename){

	fin.open(pFilename);

	if(fin.fail()){
	        cerr << "   Fehler: Konnte " << pFilename << " nicht finden" << endl;
        	exit (1);
	}
	
	m_Room= new CRoom(fin);
	
	// Name des Startraumes ermittlen
	// 1. Zeile in der Datenbasis: <start> name
	string startRoom;
	
	fin>>startRoom>>startRoom;     
	
	m_Room->readRoomInfo(startRoom);
//	m_Room->display();

}

void CGame::start(){
	string aRoom;
	
	while(1){
		// aktuellen Raum ausgeben
		//m_Room->display();
		// Prompt ausgeben
		cout  << "   Befehle: schau, nord, sued, west, ost, hilfe, ?, ende" << endl;
		cout  << m_Room->getCurrentRoom() <<":> ";

		//Benutzereingabe lesen
		string strInput = "";
		cin >> strInput;

		if(strInput == "schau"){
			m_Room->display();			
		}
		else if(strInput == "nord"){
			aRoom= m_Room->getRoomNorth();
			m_Room->moveto(aRoom);	
			m_Room->display();			
		}
		else if(strInput == "ost"){
			aRoom= m_Room->getRoomEast();
			m_Room->moveto(aRoom);	
			m_Room->display();			
		}
		else if(strInput == "sued"){
			aRoom= m_Room->getRoomSouth();
			m_Room->moveto(aRoom);	
			m_Room->display();			
		}
		else if(strInput == "west"){
			aRoom= m_Room->getRoomWest();
			m_Room->moveto(aRoom);	
			m_Room->display();			
		}
		else if(strInput == "ende"){
			return ;			
		}
		else if(strInput == "hilfe" || strInput == "?"){
			cout  << "   Befehle: schau, nord, sued, west, ost, hilfe, ?, ende" << endl;
		}
		else{
			cout << endl << "   Befehl unbekannt ???" << endl;
		}
	
	}//while

}

CGame::~CGame(){
	fin.close();
	delete m_Room;
}

