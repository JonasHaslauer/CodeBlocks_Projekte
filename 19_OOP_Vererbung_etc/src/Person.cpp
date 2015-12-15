#include "Person.h"

#include <sstream>
using namespace std;

// cons
Person::Person(int age, string name){
    this -> age = age;
    this -> name = name;
}

// destr
Person::~Person(){

}

// getter/setter
int Person::getAge() const{
    return age;
}

string Person::toString() const{
    ostringstream os;

    os << "... name: " << name << endl;
    os << "... age: " << age << endl;

    return os.str();
}
