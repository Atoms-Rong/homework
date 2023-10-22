#include "handle.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::setprecision;

Handle& Handle::operator=(const Handle &x){
    if(&x != this){
        delete sp;
        if(x.sp)
            sp = x.sp->clone();
        else
            sp = 0;
    }
    return *this;
}

istream& Handle::read(istream& is){
    if(sp) delete sp;

    char ch;
    is >> ch;
    if(ch == 'T'){
        sp = new Triangle(is);
    }
    else if(ch == 'C'){
        sp = new Circle(is);
    }
    else if(ch == 'R'){
        sp = new Rectangle(is);
    }
    return is;
}

istream& readinfo(istream& is, vector<Handle>& vec){
    char ch;
    Handle record;
    while(record.read(is)){
        vec.push_back(record);
    }
    return is;
}

Handle::~Handle() { delete sp;}

double Handle::area(){
    if(sp) return sp->area();
}
double Handle::circle(){
    if(sp) return sp->circle();
}

void cal_output(vector<Handle> vec){
    cout << endl << "Area" << "\t" << "Perimeter" << endl;
    for(vector<Handle>::size_type i = 0; i!= vec.size(); ++i){
        if(vec[i].area() == 0) continue;
        cout << setprecision(3) << vec[i].area() << "\t" << vec[i].circle() << endl;
    }
}

bool compare(Handle x, Handle y){
    return x.area() < y.area();
}