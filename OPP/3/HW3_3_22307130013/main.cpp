#include "function.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main(){
	// write your code here
	vector<int> v1;
	vector<double> v2;
	vector<string> v3;

	srand(time(NULL));
	for (vector<int>::size_type i = 0; i < 10; ++i){
		v1.push_back(rand() % 100);
	}
	cout << "the integer list :" << endl;
	print(v1);
	cout << "the sum of the integer list:" << accumulate(v1.begin(), v1.end(), 0) << endl;
	cout << "the max element in the integer list:" << *max_element(v1.begin(), v1.end()) << endl;
	cout << "the min element in the integer list:" << *min_element(v1.begin(), v1.end()) << endl << endl;

	for (vector<double>::size_type i = 0; i < 10; ++i){
		double num = 0.0;
		for(int j = 0; j < 7; ++j){
			num = num / 10.0 + (rand() % 10);
		}
		v2.push_back(num);
	}
	cout << "the double list :" << endl;
	print(v2);
	cout << "the sum of the double list:" << accumulate(v2.begin(), v2.end(), 0.0) << endl;
	cout << "the max element in the double list:" << *max_element(v2.begin(), v2.end()) << endl;
	cout << "the min element in the double list:" << *min_element(v2.begin(), v2.end()) << endl << endl;

	for(vector<string>::size_type i = 0; i < 10; ++i){
		string::size_type st = rand() % 6 + 1;
		string s;
		for(string::size_type j = 0; j < st; ++j){
			s.push_back((char)('a' + rand() % 26));
		}
		v3.push_back(s);
	}
	cout << "the string list :" << endl;
	print(v3);
	cout << "the concatenation of the string list:" << accumulate(v3.begin(), v3.end(), string()) << endl;
	cout << "the max element in the string list:" << *max_element(v3.begin(), v3.end()) << endl;
	cout << "the min element in the string list:" << *min_element(v3.begin(), v3.end()) << endl;

	return 0;
}
