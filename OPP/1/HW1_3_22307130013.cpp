#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    cout << "Enter the baby's birthday: ";
    int y,m,d;
    cin >> y >> m >> d;
    cout << "The baby's 100-day date is: ";
    for(int i = 0; i < 99; ++i){
        if((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) month[2] = 29;
        else month[2] = 28;
        if(m == 12 && d == 31){
            ++y; 
            m = d = 1;
        }
        else if(d == month[m]){
            ++m;
            d = 1;
        }
        else{
            ++d;
        }
    }
    cout << y << " " << m << " " << d << endl;
    return 0;
}