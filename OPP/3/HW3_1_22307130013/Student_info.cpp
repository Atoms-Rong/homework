#include "Student_info.h"
#include <vector>
#include <iostream>

using std::istream;
using std::vector;
// write your code

bool compare(const Core& x, const Core& y){
    if(x.homework.size() == 0 && y.homework.size() != 0) return 1;
    else if(y.homework.size() == 0) return 0;
    else if(x.totgrade == y.totgrade) return x.name < y.name;
    else return x.totgrade >= y.totgrade;
}

std::istream& read(std::istream& is, Core& s){
    is >> s.name >> s.midterm >> s.finall;

    read_hw(is, s.homework);
    return is;
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