#include "Queue.h"
#include <iostream>


int main(){
	using namespace std;
	Queue q;
	int cnt = 1;
	cout << "\t\t食堂某个窗口高峰期的排队状况模拟: " << endl;
	for(int t = 0; ; ++t){
		if(q.full()){
			cout << "\t\t该窗口排队人数已达到50人! 请分流! " << endl;
			cout << "\t" << "队首人员于" << q.front_time() << "s入队." << endl;
			cout << "\t" << "队尾人员于" << q.tail_time() << "s入队." << endl;
			break;
		}
		if(t % 8 == 0){
			cout << t << "s: 第" << cnt << "人进队." << endl;
			q.push(cnt, t);
			++cnt;
		}
		if(t != 0 && t % 25 == 0){
			cout << "\t\t" << t << "s: 第" << q.front_data() << "人出队." << endl;
			q.pop();
		}
	}
	return 0;
}
