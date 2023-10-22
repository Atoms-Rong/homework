#include <iostream>
#include "date.h"
#include <stdexcept>

using std::cin;     
using std::cout;
using std::endl;
using std::domain_error;

int main(){
    try{
        cout << "请输入两个日期(年月日，以空格分隔):" << endl;
        Date d1(cin), d2(cin);
        Date da(d1),mo(d1),ye(d1);
        cout << "日期一:";
        d1.print();
        cout << "日期二:";
        d2.print();
        cout << "两个日期相隔天数为:" << inteval(d1, d2) << endl;
        da.addDay();
        cout << "给日期一增加一天为:";
        da.print(); 
        mo.addMonth();
        cout << "给日期一增加一月为:";
        mo.print();
        ye.addYear();
        cout << "给日期一增加一年为:";
        ye.print();
    }
    catch(domain_error e){
        cout << e.what() << endl;
    }
    
    return 0;
}