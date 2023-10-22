#include <iostream>

using namespace std;

void quickSort(int *a){
    int n = sizeof(a) / sizeof(a[0]);
    cout << n << endl;
    int l = 0, r = n - 1;
    while(l < r){
        while(l < r && a[l] <= a[r]){
            --r;
        }
        if(l < r){
            int t = a[l];
            a[l] = a[r];
            a[r] = t;
            ++l;
        }
        while(l < r && a[l] <= a[r]){
            ++l;
        }
        if(l < r){
            int t = a[l];
            a[l] = a[r];
            a[r] = t;
            --r;
        }
    }
}

int main(){
    int a[5] = {1, 3, 2, 5, 4};
    
    quickSort(a);
    for(int i = 0; i < 5; ++i){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}