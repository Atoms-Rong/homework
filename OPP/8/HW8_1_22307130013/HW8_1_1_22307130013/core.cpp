#include "core.h"
#include <vector>
#include <iostream>
#include "grade.h"
#include <algorithm>

using std::istream;
using std::min;

bool compare(const Core& x, const Core& y){
    return x.name() < y.name();
}

bool compare_grade(const Core& x, const Core& y){
    return x.grade() < y.grade();
}

bool cmp(const Core* x, const Core* y){
    return compare(*x, *y);
}

Core::Core(istream& is){
    read(is);
}

Grad::Grad(istream& is){
    read(is);
}

istream& Core::read_common(std::istream& is){
    is >> n >> midterm >> finall;
    return is;
}

istream& Core::read(std::istream& is){
    read_common(is);
    read_hw(is, homework);
    return is;
}

istream& Grad::read(std::istream& is){
    read_common(is);
    is >> thesis;
    read_hw(is, homework);
    return is;
}

double Core::grade() const{
    return ::grade(midterm, finall, homework);
}

double Grad::grade() const{
    return min(Core::grade(), thesis);
}

std::istream& read_hw(std::istream& in, vector<double>& hw){
    if(in){
        hw.clear();

        double x;
        while(in >> x)
            hw.push_back(x);
        
        in.clear();
    }
    return in;
}