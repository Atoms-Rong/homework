#include"Student_info.h"
#include"grade.h"
#include<list>
using std::list;
list<Core> extract_fails(list<Core>& s){
	list<Core> fails;
	list<Core>::iterator it = s.begin();
	
	while(it != s.end()){
		if(fgrade(*it)){
			fails.push_back(*it);
			it = s.erase(it);
		}
		else{
			++it;
		}
	}
	return fails;
}
