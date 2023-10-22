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
#include <list>

int main() {
	using namespace std;
	list<Core> students;
	Core record;
	int mlen = 0;
	// Write your code !
	while(read(cin, record)){
		students.push_back(record);
		mlen = mlen > record.name.size() ? mlen : record.name.size();
	}
	for(list<Core>::iterator it = students.begin(); it != students.end(); ++it){
		it->totgrade = grade(*it);
	}
	students.sort(compare);
	for(list<Core>::iterator it = students.begin(); it != students.end() && it->homework.size() == 0;){
		try{
			cout << it->name  << string(mlen - it->name.size() + 1, ' ');
			it = students.erase(it);
			throw domain_error("student has done no homework");
		}
		catch(domain_error e){
			cout << e.what() << endl;
		}
	}
	list<Core> fails = extract_fails(students);
	cout << endl << "Passing students: " << endl;
	for(list<Core>::iterator it = students.begin(); it != students.end(); ++it){
		cout << it->name  << string(mlen - it->name.size() + 1, ' ') << it->totgrade << endl;
	}
	cout << endl << "Failing students: " << endl;
	for(list<Core>::iterator it = fails.begin(); it != fails.end(); ++it){
		cout << it->name  << string(mlen - it->name.size() + 1, ' ') << it->totgrade << endl;
	}
	return 0;
}
