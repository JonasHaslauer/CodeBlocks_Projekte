#include <string>
#include "Person.h"

using namespace std;

#ifndef MANAGER_H
#define MANAGER_H

class Manager : public Person
{
    public:
        Manager( int age, string name, double fixedSalary );
        double getWage(){return fixedSalary;}
        string toString();
    protected:
    private:
        double fixedSalary;
};

#endif // MANAGER_H
