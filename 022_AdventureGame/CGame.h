#ifndef CGame_h
#define CGame_h CGame_h

#include "CRoom.h"
#include "CPlayer.h"
#include <vector>
#include <fstream>
using namespace std;

class CGame {
private:
	ifstream fin;
	CRoom *m_Room;
	CPlayer *player;
    vector<CItem*> items;
    vector<CMonster*> monsters;

    int playerScore;

public:
	CGame(const char* pFilename);
	void start(void);
	~CGame();
	void displayCommands();
};

#endif
