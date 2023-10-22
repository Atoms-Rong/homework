#include <iostream>
#include "city_temp.h"
#include <vector>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::domain_error;
using std::istream;
using std::ostream;

istream& read(istream& in, const vector<city_temp>& cities){
    if(in){
        city_temp record;
        cities.clear();
        
        while(in >> record.name >> record.tmp){
            cities.push_back(record);
        }
    }
    in.clear();
    
}
double average(const vector<city_temp>&);
void deviate(const vector<city_temp>&, const double&);
ostream& print(ostream&, const vector<city_temp>&, const double&);

int main()
{
    vector<city_temp> cities;
    cout << "Enter city names and temperatures: " << endl;
    read(cin, cities);  //读入城市和温度数据
    try {
        double avg = average(cities);  //求平均温度(含抛出异常)
        deviate(cities, avg);  //求温度偏差并按偏差排序
        print(cout, cities, avg);  //按要求输出
    }
    catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}