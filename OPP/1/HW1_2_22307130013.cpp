#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
    int n,m;
    cout << "Enter the side length of a square: ";
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << "* ";
        }
        cout << endl;
    }
    cout << "Enter the length and width of a rectangle: ";
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        for(int j = 0 ; j < n; ++j){
            cout << "* ";
        }
        cout << endl;
    }
    cout << "Enter the base length of an isosceles triangle(odd number): ";
    cin >> n;
    for(int i = 0; i < (n+1)/2; ++i){
        for(int j = 0; j < n; ++j){
            if(j >= (n-2*i-1)/2 && j < (n+2*i+1)/2){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}