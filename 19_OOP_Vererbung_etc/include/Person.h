#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
    // Private member. Nobody can access this member
    int age;

    // Protected member.
    // Only subclasses can access this member
protected:
    string name;

public:
    // cons
    Person(int age, string name);
    // destr
    ~Person();

    // getter/setter
    int getAge() const;

    string toString() const;
    string getName(){return name;}

    double getWage()const { return 0.0;}
};
#endif
