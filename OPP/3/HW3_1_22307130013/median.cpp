// write your code
#include <vector>
#include "median.h"
#include <iostream>
#include <algorithm>
#include "Student_info.h"
#include <stdexcept>

double median(std::vector<double> hw){
    if(hw.size() == 0) return 0;
    sort(hw.begin(), hw.end());
    return (hw.size() % 2 != 0) ?  hw[hw.size()/2] : (hw[(hw.size()+1)/2]+hw[(hw.size()-1)/2])/2;
}