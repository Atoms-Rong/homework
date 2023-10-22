#include "shape.h"
#include <iostream>
#include <stdexcept>

using std::istream;
using std::cout;
using std::endl;

istream& Shape::read(istream& is){
    return is;
}

istream& Triangle::read(istream& is){
    double ra, rb, rc;
    is >> ra >> rb >> rc;
    if(ra + rb <= rc || ra + rc <= rb || rb + rc <= ra){
        cout << ra << ", " << rb << ", " << rc << " can't make a triangle." << endl;
        a = 0, b = 0, c = 0;
        return is;
    }
    a = ra;
    b = rb;
    c = rc;
    return is;
}

istream& Circle::read(istream& is){
    is >> r;
    return is;
}

istream& Rectangle::read(istream& is){
    is >> a >> b;
    return is;
}

void cal_output(const vector<Shape*>& vec){
    std::cout << "Area" << "\t" << "Perimeter" << endl;
    for(vector<Shape*>::size_type i = 0; i != vec.size(); ++i){
        std::cout << vec[i]->area() << "\t" << vec[i]->circle() << endl;
    }
}

bool compare(Shape* x, Shape* y){
    return x->area() < y->area();
}