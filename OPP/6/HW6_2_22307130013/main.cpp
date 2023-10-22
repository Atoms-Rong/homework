#include "Queue.h"
#include <iostream>


int main(){
	using namespace std;
	Queue<int> qtime;
	int cnt = 1, cntout = 1;
	cout << "\t\t食堂某个窗口高峰期的排队状况模拟: " << endl;
	for(int t = 0; ; ++t){
		if(qtime.full()){
			cout << "\t\t该窗口排队人数已达到50人! 请分流! " << endl;
			cout << "\t" << "队首人员于" << qtime.front() << "s入队." << endl;
			cout << "\t" << "队尾人员于" << qtime.behind() << "s入队." << endl;
			break;
		}
		if(t % 8 == 0){
			cout << t << "s: 第" << cnt << "人进队." << endl;
			qtime.push(t);
			++cnt;
		}
		if(t != 0 && t % 25 == 0){
			cout << "\t\t" << t << "s: 第" << cntout++ << "人出队." << endl;
			qtime.pop();
		}
	}
	Queue<int> q1(qtime), q2;
    q1.print();
    q2 = q1;
    q2.print();
	return 0;
}
