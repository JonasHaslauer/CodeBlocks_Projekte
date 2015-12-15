#include "Seller.h"
#include <sstream>

using namespace std;

Seller::Seller( int age, string name, int hours, double wage, int numberOfSales, double price ) : Worker(age, name, hours, wage)
{
    this->price = price;
    this->numberOfSales = numberOfSales;
}

string Seller::toString()const{
    ostringstream os;

    os << Worker::toString();
    os << "... numberOfSales: " << numberOfSales << endl;
    os << "... price: " << price << endl;

    return os.str();
}

double Seller::getWage() const{
    return Worker::getWage() + (numberOfSales * price);
}
