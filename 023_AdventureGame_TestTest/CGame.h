//a.hofmann dez 2004
//CGame.h

#ifndef CGame_h
#define CGame_h CGame_h

#include "CRoom.h"
#include <fstream>
using namespace std;

class CGame {
private:
	ifstream fin;
	CRoom *m_Room;	//Verweis auf Raum
public:
	CGame(const char* pFilename);
	void start(void);
	~CGame();
};

#endif
