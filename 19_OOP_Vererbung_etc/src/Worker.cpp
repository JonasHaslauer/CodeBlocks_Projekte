#include "Worker.h"
#include <sstream>

using namespace std;

Worker::Worker( int age, string name, int hours, double wage ) : Person(age, name)
{
        this->hours = hours;
        this-> wage = wage;
}

// getter/setter

string Worker::toString()const{
    ostringstream os;

    os << Person::toString();
    os << "... hours: " << hours << endl;
    os << "... wage: " << wage << endl;

    return os.str();
}

double Worker::getWage() const{
    return wage * hours;
}
