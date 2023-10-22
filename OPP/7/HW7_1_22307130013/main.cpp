#include <iostream>
#include "Str.h"
using std::cout;
using std::cin;
using std::endl;

int main(){
    cout << "please enter your first name: ";
    string name;
    cin >> name;
    cout << "please enter the number of the blanks surrounding the greeting: ";
    int blank;
    cin >> blank;
    string greeting = "Hello, " + name + " !";
    string::size_type col = greeting.size() + blank*2 + 2;
    int row = blank*2 + 3;
    for(int i = 0; i < row; ++i){
        cout << endl;
        int c = 0;
        while(c != col){
            if(i == blank+1 && c == blank+1){
                cout << greeting;
                c += greeting.size();
            }
            else{
                if(i == 0 || i == row-1 || c == 0 || c == col-1){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
                ++c;
            }
        }
    }
    cout << endl << "逐个字符输出greeting(字符之间以空格分隔):" << endl;
    for(string::size_type i = 0; i != greeting.size(); ++i){
        cout << greeting[i] << " ";
    }
    cout << endl;
    return 0;
}