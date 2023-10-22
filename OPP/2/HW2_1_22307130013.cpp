#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::domain_error;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::istream;

struct stucal{
    string word;
    int cnt;

    stucal(){
        cnt = 0;
    }

    stucal(string wd,int ct){
        word = wd;
        cnt = ct;
    }
};

istream& read_wd(istream& in, vector<string>& wd){
    if(in){
        wd.clear();

        string x;
        while(in >> x){
            wd.push_back(x);
        }
        in.clear();
    }
    return in;
}

vector<stucal> calc(const vector<string>& wd){
    vector<stucal> count;
    for(int i = 0; i < wd.size(); ++i){
        bool flag = true;
        for(int j = 0; j < count.size(); ++j){
            string a = wd[i], b = count[j].word;
            for(int k = 0; k < a.size(); ++k) 
                if(a[k] >= 'A' && a[k] <= 'Z') a[k] = a[k] - 'A' + 'a';
            for(int k = 0; k < b.size(); ++k) 
                if(b[k] >= 'A' && b[k] <= 'Z') b[k] = b[k] - 'A' + 'a';
            if(a == b) {
                flag = false;
                ++count[j].cnt;
            }
        }
        if(flag){
            count.push_back(stucal(wd[i],1));
        }
    }
    return count;
}

int calc_sum(const vector<stucal>& stcal){
    int sum = 0;
    for(int i = 0; i < stcal.size(); ++i){
        sum += stcal[i].cnt;
    }
    return sum;
}

string::size_type calc_max(const vector<string>& wd){
    string::size_type max=0;
    for(int i = 0; i < wd.size(); ++i){
        if(max < wd[i].size()) max = wd[i].size();
    }
    return max;
}

int main(){
    cout << "Enter some English words: " << endl;
    
    vector<string> words;
    read_wd(cin, words);
    vector<stucal> count = calc(words);
    string::size_type len = calc_max(words);
    try{
        int sum = calc_sum(count);
        if(sum == 0) 
            throw domain_error("No words entered. Please try again!");
        cout << "number of the words: " << sum << endl;
        for(int i = 0; i < count.size(); ++i){
            cout << count[i].word;
            string space(len - count[i].word.size() + 1 ,' ');
            cout << space << count[i].cnt << endl;
        }
    }catch(domain_error e){
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}