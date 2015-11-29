//fraction.cpp

#include "fraction.h"

#include <sstream>
using namespace std;

Fraction::Fraction(double nom, double denom){
    this->nominator = nom;
    this->denominator = denom;
}

Fraction::Fraction(const Fraction& other){
    this->nominator = other.nominator;
    this->denominator = other.denominator;
}

Fraction Fraction::mul(const Fraction& other){
    return Fraction(this->nominator * other.nominator, this->denominator * other.denominator);
}

string Fraction::toString() const{
    ostringstream os;

    os << "[" << nominator << "/" << denominator << "]" << endl;

    return os.str();
}
