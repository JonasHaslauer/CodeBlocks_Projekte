#include "Company.h"
#include <sstream>

Company::Company (string name)
{
    this->name = name;
}

void Company::addEmployee(Person* p){
    employee.push_back(p);
}

void Company::removeEmployee(int age){
    vector<Person*>::iterator it;
    for(it = employee.begin(); it != employee.end(); it++){
        if((*it)->getAge() == age){
            employee.erase(it);
        }
    }
}

double Company::getPayroll(){
    double sum = 0.0;
    vector<Person*>::iterator it;
    for(it = employee.begin(); it != employee.end(); it++){
        sum += (*it)->getWage();
    }
    return sum;
}

string Company::toString(){
    ostringstream os;

    os << "MITARBEITER:" << endl << endl;

    vector<Person*>::iterator it;
    for(it = employee.begin(); it != employee.end(); it++){
        os << "Name: " << (*it)->getName() << "\t|\t" << "Alter: " << (*it)->getAge() << endl;
    }

    return os.str();
}
