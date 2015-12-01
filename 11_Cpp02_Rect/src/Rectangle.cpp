#include "Rectangle.h"

#include <sstream>
using namespace std;


Rectangle::Rectangle(int l, int w)
{
    this->length = l;
    this->width = w;
}

Rectangle::Rectangle(const Rectangle& other){
    this->length = other.length;
    this->width = other.width;
}

int Rectangle::getArea(){
    return (this->length * this->width);
}

string Rectangle::toString() const{
    ostringstream os;

    for(int i = 0; i < width; i++){
        for(int j = 0; j < length; j++){
            os << "*";
        }
        os << endl;
    }
    return os.str();
}
