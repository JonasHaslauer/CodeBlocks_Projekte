#include "Manager.h"
#include <sstream>
using namespace std;


Manager::Manager( int age, string name, double fixedSalary ) : Person(age, name)
{
    this->fixedSalary = fixedSalary;
}

string Manager::toString(){
    ostringstream os;

    os << Person::toString();
    os << "... fixedSalary: " << fixedSalary << endl;

    return os.str();
}
