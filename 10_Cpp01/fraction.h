// fraction.h

#pragma once

#include <string>
using namespace std;

class Fraction{
    private:
    //private data members, data fields
        double nominator;
        double denominator;

    public:
        // const, destr.
        Fraction(double nom = 1.0, double denom = 1.0);
        Fraction(const Fraction& other); //copy constructor

        //getter/setter

        //general member functions / methods
        Fraction mul(const Fraction& other);
        string toString() const;
};
