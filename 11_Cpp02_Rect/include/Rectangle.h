#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
using namespace std;

class Rectangle
{
    public:
        Rectangle(int l = 1, int w = 1);
        Rectangle(const Rectangle& other);
        int getArea();
        string toString() const;

    private:
        int length;
        int width;
};

#endif // RECTANGLE_H
