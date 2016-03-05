// demo f. die verwendung von tinyxml 
// ahofmann, 2016-01-25
// test_adv_questions.cpp
//
// g++ tinyxml2.cpp adv_questions.cpp -o adv_questions.exe
// ./adv_questions.exe
//

#include "tinyxml2.h"

#include <iostream>

using namespace tinyxml2;
using namespace std;


/*
 * Aufbau der Datei adv_questions.xml 

<?xml version="1.0" encoding="UTF-8"?>

<fragen>

<frage>
<fragentext>
	BEISPIEL: SINGLE-CHOICE-Frage
	Objekte, die nicht mehr benötigt werden, müssen gelöscht
	werden. Dazu wird eine boolsche Variable remove verwendet. 
	In welcher Klasse wird Sie definiert?
	a) Sprite b) Rocket c) GamePanel d) Explosion
</fragentext>
<loesungstext>a</loesungstext>
<punkte>10</punkte>
</frage>

...
</fragen>

 */

int main(int argc, const char *argv[]) {

	// open document
	XMLDocument doc;
	int ret= doc.LoadFile("adv_questions.xml");
	if (ret!=0){
		cerr << "error open adv_questions.xml" << endl;
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
    if(proot) {

		// FIRST ... frage
        pquestion = proot->FirstChildElement("frage");
		while (pquestion){
			cout << "************************************************* " << endl;
			cout << "... FRAGE ... " << endl;
			cout << "************************************************* " << endl;
			pquestiontxt= pquestion->FirstChildElement("fragentext");
			cout << pquestiontxt->GetText() << endl<<endl;

			cout << "... LÖSUNG ... " << endl;
			panswertxt= pquestion->FirstChildElement("loesungstext");
			cout <<  panswertxt->GetText() << endl<<endl;

			cout << "... PUNKTE ... " << endl;
			ppoint= pquestion->FirstChildElement("punkte");
			cout <<  ppoint->GetText() << endl<<endl;

			cout << endl;

			// NEXT ... frage
			pquestion= pquestion->NextSiblingElement("frage");
		}

	}

	return 0;
}

