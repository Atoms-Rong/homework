#include "Queue.h"
#include <iostream>


int main(){
	using namespace std;
	Queue<int> qtime;
	int cnt = 1, cntout = 1;
	cout << "\t\tʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ��: " << endl;
	for(int t = 0; ; ++t){
		if(qtime.full()){
			cout << "\t\t�ô����Ŷ������Ѵﵽ50��! �����! " << endl;
			cout << "\t" << "������Ա��" << qtime.front() << "s���." << endl;
			cout << "\t" << "��β��Ա��" << qtime.behind() << "s���." << endl;
			break;
		}
		if(t % 8 == 0){
			cout << t << "s: ��" << cnt << "�˽���." << endl;
			qtime.push(t);
			++cnt;
		}
		if(t != 0 && t % 25 == 0){
			cout << "\t\t" << t << "s: ��" << cntout++ << "�˳���." << endl;
			qtime.pop();
		}
	}
	Queue<int> q1(qtime), q2;
    q1.print();
    q2 = q1;
    q2.print();
	return 0;
}
