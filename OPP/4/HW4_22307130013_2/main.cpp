#include <iostream>
#include "date.h"
#include <stdexcept>

using std::cin;     
using std::cout;
using std::endl;
using std::domain_error;

int main(){
    try{
        cout << "��������������(�����գ��Կո�ָ�):" << endl;
        Date d1(cin), d2(cin);
        Date da(d1),mo(d1),ye(d1);
        cout << "����һ:";
        d1.print();
        cout << "���ڶ�:";
        d2.print();
        cout << "���������������Ϊ:" << inteval(d1, d2) << endl;
        da.addDay();
        cout << "������һ����һ��Ϊ:";
        da.print(); 
        mo.addMonth();
        cout << "������һ����һ��Ϊ:";
        mo.print();
        ye.addYear();
        cout << "������һ����һ��Ϊ:";
        ye.print();
    }
    catch(domain_error e){
        cout << e.what() << endl;
    }
    
    return 0;
}