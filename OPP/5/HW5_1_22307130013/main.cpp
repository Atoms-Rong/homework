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
#include <fstream>
#include <cstdlib>
#include <ctime>
int main() {
	using namespace std;
	vector<Core> students;
	Core record;
	int mlen = 0;
	ifstream infile("grades");
	ofstream outfile("final");

	while(record.read(infile)){
		students.push_back(record);
		mlen = mlen > record.name().size() ? mlen : record.name().size();
	}
	sort(students.begin(), students.end(), compare);
	for(int i = 0; i < students.size(); ++i){
		cout << students[i].name()  << string(mlen - students[i].name().size() + 1, ' ');
		outfile << students[i].name()  << string(mlen - students[i].name().size() + 1, ' ');
		try{
			if(!students[i].valid()) throw domain_error("student has done no homework");
			cout << letter_grade(students[i].grade()) << endl;
			outfile << letter_grade(students[i].grade())  << endl;
		}
		catch(domain_error e){
			cout << e.what() << endl;
			outfile << e.what() << endl;
		}
	}
	srand(time(NULL));
	int arr[11];
	for(int i = 0;i < 11; ++i){
		arr[i] = rand() % 100;
	}
	cout << endl << "the following is the result of testing median function on array" << endl;
	cout << "the random array is" << endl;
	for(int i = 0;i < 11; ++i){
		cout << arr[i] << " ";
	}
	cout << endl << "the median of the array is: " << median(arr, arr + 11) << endl;
	cout  << "after median function called, the array is unchanged:" << endl;
	for(int i = 0;i < 11; ++i){
		cout << arr[i] << " ";
	}
	return 0;
}
