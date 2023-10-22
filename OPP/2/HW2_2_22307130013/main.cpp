#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

int main() {
	using namespace std;
	vector<Core> students;
	Core record;
	int mlen = 0;
	// Write your code !
	while(read(cin, record)){
		students.push_back(record);
		mlen = mlen > record.name.size() ? mlen : record.name.size();
	}
	for(int i = 0; i < students.size(); ++i){
		students[i].totgrade = grade(students[i]);
	}
	sort(students.begin(), students.end(), compare);
	for(int i = 0; i < students.size(); ++i){
		cout << students[i].name  << string(mlen - students[i].name.size() + 1, ' ');
		try{
			if(students[i].homework.size() == 0) throw domain_error("student has done no homework");
			cout << students[i].totgrade << endl;
		}
		catch(domain_error e){
			cout << e.what() << endl;
		}
	}
	return 0;
}
