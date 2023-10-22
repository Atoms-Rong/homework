#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

const long long MOD = 1e8;

using std::vector;
using std::cout;
using std::cin;
using std::endl;

struct bigint{
    vector<long long> num;
    int l;

    bigint(){
        num.clear();
        num.push_back(0);
        l = 1;
    }
};

bigint add(bigint a, bigint b){
    if(a.l < b.l){
        bigint t = a; a = b; b = t;
    }
    for(int i = 0; i < a.l && i < b.l; ++i){
        long long t = a.num[i] + b.num[i];
        for(int j = i; j < a.l - 1; ++j){
            a.num[j] = t % MOD;
            t = a.num[j + 1] + t / MOD;
        }
        if(t / MOD > 0){
            a.num[a.l - 1] = t % MOD;
            ++a.l;
            a.num.push_back(0);
            a.num[a.l - 1] = t / MOD;
            break;
        }
        else a.num[a.l - 1] = t % MOD;
    }
    return a;
}

bigint mul(bigint a, long long b){
    vector<bigint> s;
    bigint ans;
    for(int i = 0; i < a.l; ++i){
        bigint r;
        long long t = a.num[i] * b;
        int j = 0;
        while(j < i){
            r.num.push_back(0);
            ++r.l;
            ++j;
        }
        r.num[i] = t % MOD;
        if(t / MOD > 0){
            ++r.l;
            r.num.push_back(t / MOD);
        }
        s.push_back(r);
    }
    for(int i = 0; i < s.size(); ++i){
        ans = add(s[i], ans);
    }
    return ans;
}

void print(bigint a){
    cout << a.num[a.l - 1];
    for(int i = a.l - 2; i >= 0; --i){
        printf("%08d", a.num[i]);
    }
}

int main(){
    cout << "Enter n(1<=n<=50): ";
    int n;
    cin >> n;
    bigint ans ,f;
    f.num[0] = 1;
    for(int i = 1; i < n; ++i){
        cout << i << "!+";
        f = mul(f, i);
        ans = add(ans, f);
    }
    cout << n << "!=";
    f = mul(f, n);
    ans = add(ans, f);
    print(ans);
    return 0;
}