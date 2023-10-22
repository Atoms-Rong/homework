#include <iostream>
#include "selectSort.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;

int main(){
    srand(time(NULL));
    unsigned int size = rand() % 10 + 10;
    vector<int> vec;
    list<double> lis;
    string str;
    for(unsigned int i = 0; i < size; ++i){
        vec.push_back(rand() % 100);
        lis.push_back(rand() % 100000 / pow(10, rand() % 5));
        str.push_back(rand() % 26 + 'A'); 
    }
    selectSort(vec.begin(), vec.end());
    selectSort(lis.begin(), lis.end());
    selectSort(str.begin(), str.end());
    return 0;
}