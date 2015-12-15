#include <string>
#include "Person.h"

#ifndef WORKER_H
#define WORKER_H

class Worker : public Person
{
private:
    int hours;
    double wage;

public:
    // cons
    Worker( int age, string name,
            int hours, double wage );

    // getter/setter
    string toString()const;

    double getWage() const;
};
#endif
