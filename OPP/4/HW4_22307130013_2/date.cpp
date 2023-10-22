#include "date.h"
#include <iostream>
#include <stdexcept>

using std::istream;     
using std::cout;
using std::endl;        
using std::domain_error;

Date::Date(int y_, int m_, int d_) : y(y_), m(m_), d(d_) {}

Date::Date(istream& in){
    in >> y >> m >> d;
    if(!isvy()){
        throw domain_error("invalid year");
    }
    else if(!isvm()){
        throw domain_error("invalid month");
    }
    else if(!isvd()){
        throw domain_error("invalid day");
    }
}

Date::Date(Date& a): y(a.year()), m(a.month()), d(a.day()) {}

void Date::addYear(){
        if(isleap() && m == 2 && d == 29){
            d = 28;
        }
        ++y;
    }
void Date::addMonth(){
    if(m == 12){
        ++y; m = 1;
    }
    else if(m == 1 && isleap()){
        if(d > 29){
            d = 29; m = 2;
        }
    }
    else if(d > mon[m+1]){
        ++m; d = mon[m];
    }
    else{
        ++m;
    }
}

void Date::addDay(){
    if(m == 12 && d == 31){
        ++y; m = 1; d = 1;
    }
    else if(m == 2 && isleap()){
        if(d == 29){
            ++m; d = 1;
        }
        else{
            ++d;
        }
    }
    else if(d == mon[m]){
        ++m; d = 1;
    }
    else{
        ++d;
    }
}

int inteval(Date d1,Date d2){
    int cnt = 0;
    Date nd1, nd2;
    if(d1.year() > d2.year() || d1.year() == d2.year() && d1.month() > d2.month() || d1.month() == d2.month() && d1.day() > d2.day()){
        nd1 = d2;
        nd2 = d1;
    }
    while(!(nd1.year() == nd2.year() && nd1.month() == nd2.month() && nd1.day() == nd2.day())){
        ++cnt;
        nd1.addDay();
    }
    return cnt;
}