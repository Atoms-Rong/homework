#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    cout << "please enter your first name: ";
    string name;
    cin >> name;
    cout << "please enter the number of the blanks surrounding the greeting: ";
    int blank;
    cin >> blank;
    string greeting = "hello " + name + " !";
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
    return 0;
}