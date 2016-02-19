#ifndef CGame_h
#define CGame_h CGame_h

#include "CRoom.h"
#include <vector>
#include <fstream>
using namespace std;

class CGame {
private:
	ifstream fin;
	CRoom *m_Room;
    vector<CItem*> items;
    int playerScore;

public:
	CGame(const char* pFilename);
	void start(void);
	~CGame();
	void displayCommands();
};

#endif
