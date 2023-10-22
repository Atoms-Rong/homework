#include <iostream>
#include "Str.h"
#include "vector.h"
#include <algorithm>
#include <vector>
#include <string>

using std::sort;
using std::cout;
using std::cin;
using std::endl;
//using std::string;
using std::max;

int main(){
    cout << "Enter some text:";
    vector<string> words;
    string record;
    string::size_type mlen = 0;
    while(cin >> record){
        words.push_back(record);
        mlen = max(record.size(), mlen);
    }
    sort(words.begin(), words.end());
    int cnt = 1;
    string pre = words[0];
    for(vector<string>::size_type i = 1; i != words.size(); ++i){
        if(pre != words[i]){
            cout << pre << string(mlen - pre.size() + 1,' ') << cnt << endl;
            pre = words[i];
            cnt = 1;
        }
        else{
            ++cnt;
        }
    }
    cout << pre << string(mlen - pre.size() + 1,' ') << cnt << endl;
    return 0;
}
