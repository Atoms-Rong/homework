#include "Queue.h"
#include <iostream>


int main(){
	using namespace std;
	Queue q;
	int cnt = 1;
	cout << "\t\tʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ��: " << endl;
	for(int t = 0; ; ++t){
		if(q.full()){
			cout << "\t\t�ô����Ŷ������Ѵﵽ50��! �����! " << endl;
			cout << "\t" << "������Ա��" << q.front_time() << "s���." << endl;
			cout << "\t" << "��β��Ա��" << q.tail_time() << "s���." << endl;
			break;
		}
		if(t % 8 == 0){
			cout << t << "s: ��" << cnt << "�˽���." << endl;
			q.push(cnt, t);
			++cnt;
		}
		if(t != 0 && t % 25 == 0){
			cout << "\t\t" << t << "s: ��" << q.front_data() << "�˳���." << endl;
			q.pop();
		}
	}
	return 0;
}
