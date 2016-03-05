#ifndef Question_h
#define Question_h

#include <string>
using namespace std;

class Question{

private:
    string fragenText;
    string loesungsText;
    int punkte;

public:
    Question(string fragenText, string loesungsText, int punkte)
    {
    this->fragenText = fragenText;
    this->loesungsText = loesungsText;
    this->punkte = punkte;
    }

    ~Question();

    string getFragenText(){ return fragenText; }
    string getLoesungsText(){ return loesungsText; }
    int getPunkte(){ return punkte; }

};

#endif // Question_h
