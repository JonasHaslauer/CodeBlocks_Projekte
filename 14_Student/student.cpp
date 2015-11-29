
#include "student.h"
#include <sstream>

using namespace std;

Student::Student(string name, double w){
    name_ = name;
    weight_ = w;
}

string Student::toString() const{
    ostringstream os;

    os << "...name " << name_ << endl;
    os << "...weight " << weight_ << endl;
    return os.str();
}

double Student::getweight() const{

    return weight_;
}


