#include "find.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "find.h"

using std::cin;
using std::cout;
using std::list;
using std::string;
using std::vector;

int main(){
	// write your code here
	srand(time(NULL));
	vector<int> vec;
	vector<string> v;
	list<int> lis;
	list<string> l;

	for(vector<int>::size_type i = 0; i < 13; ++i){
		vec.push_back(rand() % 20);
		lis.push_back(rand() % 20);
	}
	cout << "Random integer vector 1:" << endl;
	print(vec);
	cout << "Random integer vector 2:" << endl;
	print(lis);
	cout << "Vector in common:" << endl;
	print(find_same(vec, lis));

	string record;
	cout << "Enter some words for string list 1:" << endl;
	while(cin >> record){
		v.push_back(record);
	}
	cout << "Enter some words for string list 2:" << endl;
	cin.clear();
	while(cin >> record){
		l.push_back(record);
	}
	cout << "List in commom:" << endl;
	print(find_same(v, l));
	return 0;
}
