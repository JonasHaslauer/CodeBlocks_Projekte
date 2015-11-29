

#include "schoolclass.h"
#include "student.h"
#include <sstream>
#include <vector>

using namespace std;

schoolclass::schoolclass(string name){
    name_ = name;

}

string schoolclass::toString() const{
    ostringstream os;

    vector<Student*>::const_iterator it;

    os << "Classname " << name_ <<endl;

    for(it = students.begin(); it!= students.end(); it++){
        os << (*it)-> toString() <<endl;
    }
    /*
    for(int i=0; i<students.size(); i++){
        os << students[i] -> toString() <<  endl;
    }


    for(auto pstudent : students){
        os << pstudent->toString() << endl;
    }
    */
    return os.str();
}

Student schoolclass::getMassiest(){
    vector<Student*>::const_iterator it;
    Student* teststudent;

    /*for( int i=0; i<students.size(); i++){
        teststudent = students[0];

        if (students[i] -> getweight() > students[i+1] -> getweight()){
            teststudent = students[i];
        }
    }*/
    for(it = students.begin(); it!= students.end(); it++){
        if(it == students.begin()){
            teststudent = (*it);
        }
        if(teststudent -> getweight() < (*it+1)->getweight())
        {
            teststudent = (*it+1);
        }
    }
    return *teststudent;
}

void schoolclass::add( Student& aStudent){
    students.push_back(&aStudent);
}
