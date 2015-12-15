#include "Worker.h"

#ifndef SELLER_H
#define SELLER_H


class Seller : public Worker
{
    public:
        Seller(int age, string name, int hours, double wage, int numberOfSales, double price);
        string toString()const;
        double getWage() const;

    protected:
    private:
        int numberOfSales;
        double price;
};

#endif // SELLER_H
