
#ifndef ____schoolclass__
#define ____schoolclass__

#include <stdio.h>
#include <string>
#include <vector>
#include "student.h"
using namespace std;

class schoolclass{
private:
    string name_;
    vector <Student*> students;

public:
    schoolclass(string name);
    string toString() const;
    void add( Student& aStudent);
    Student getMassiest();
};

#endif /* defined(____schoolclass__) */
