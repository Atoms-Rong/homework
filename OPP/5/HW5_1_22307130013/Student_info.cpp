#include "Student_info.h"
#include <vector>
#include <iostream>
#include "grade.h"

using std::istream;
using std::vector;
// write your code

// bool compare1(const Student_info& x, const Student_info& y){
//     if(x.valid() && !y.valid()) return 0;
//     else if(!x.valid()) return 1;
//     else return x.grade() >= y.grade();
// }

bool compare(const Core& x, const Core& y){
    return x.name() < y.name();
}

Core::Core(): midterm(0), finall(0) {}

Core::Core(istream& is){
    read(is);
}

istream& Core::read(std::istream& is){
    is >> n >> midterm >> finall;
    read_hw(is, homework);
    return is;
}

double Core::grade() const{
    return ::grade(midterm, finall, homework);
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