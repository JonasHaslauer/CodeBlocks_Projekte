
#ifndef ____student__
#define ____student__

#include <stdio.h>
#include "string"
using namespace std;
class Student{

private:
    string name_;
    double weight_;
public:
    Student (string name, double w);
    string toString() const;
    double getweight() const;

};

#endif /* defined(____student__) */
