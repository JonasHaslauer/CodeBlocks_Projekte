#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
using namespace std;
#include "Person.h"

class Company {

private:
    vector<Person*>  employee;
    string name;

public:
    Company (string name);

    void addEmployee(Person* p);
    void removeEmployee(int age);

    double getPayroll();

    string toString();
};
#endif
