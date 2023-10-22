#include <iostream>
#include "core.h"
#include "grade.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <fstream>

using std::max;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::ifstream;

int main(){
    vector<Student_info> students;
    Student_info record;
    char ch;
    string::size_type maxlen = 0;
    ifstream in("grades2");

    while(record.read(in)){
        maxlen = max(record.name().size(), maxlen);
        students.push_back(record);
    }

    sort(students.begin(), students.end(), Student_info::compare);

    for(vector<Core*>::size_type i = 0; i != students.size(); ++i){
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
        try{
            double final_grade = students[i].grade();
            cout << final_grade << endl;
        }catch(std::domain_error e){
            cout << e.what() << endl;
        }
    }
    
    return 0;
}