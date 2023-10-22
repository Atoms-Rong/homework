#include <iostream>
#include <vector>
#include "shape.h"
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "handle.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::setprecision;

int main(){
    vector<Handle> shapes;
    ifstream infile("shapes");
    readinfo(infile, shapes);
    sort(shapes.begin(), shapes.end(), compare);
    cal_output(shapes);
    return 0;
}