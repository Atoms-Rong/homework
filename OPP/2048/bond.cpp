#include "bond.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::string;
using std::endl;

Bond::Bond(){
    s = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            arr[i][j] = 0;
        }
    }
}

void Bond::print() const {
    for(int i = 0; i < 4; ++i){
        print_line();
        for(int j = 0; j < 4; ++j){
            int l = 1;
            int num = arr[i][j];
            while(num /= 10) ++l;
            if(arr[i][j]) cout << "| "<< arr[i][j] << string(4 - l, ' ');
            else cout << "|     ";
        }
        cout << "|" << endl;
    }
    print_line();
}

void Bond::random(int a){
    srand(time(0));
    int x, y;
    do{
        x = rand() % 4, y = rand() % 4;
    }while(arr[x][y]);
    int num = rand() % 5;
    if(num == 4 && a == 0){
        arr[x][y] = 4;
    }
    else{
        arr[x][y] = 2;
    }
}

int Bond::merge(const char& dir){
    int sum = 0;
    if(dir == 'l')
        for(int i = 0; i < 4; ++i)
            for(int k = 0; k < 4; ++k)
                for(int j = 1; j < 4; ++j){
                    if(arr[i][j] == 0) continue;
                    else if(arr[i][j] == arr[i][j - 1]){
                        arr[i][j-1] *= 2;
                        arr[i][j] = 0;
                        sum += arr[i][j-1];
                    }
                    else if(arr[i][j-1] == 0){
                        arr[i][j-1] = arr[i][j];
                        arr[i][j] = 0;
                    }
                    else if(arr[i][j-1] != arr[i][j]) continue;
                }
    else if(dir == 'r')
        for(int i = 0; i < 4; ++i)
            for(int k = 0; k < 4; ++k)
                for(int j = 2; j >= 0; --j){
                    if(arr[i][j] == 0) continue;
                    else if(arr[i][j] == arr[i][j+1]){
                        arr[i][j+1] *= 2;
                        arr[i][j] = 0;
                        sum += arr[i][j+1];
                    }
                    else if(arr[i][j+1] == 0){
                        arr[i][j+1] = arr[i][j];
                        arr[i][j] = 0;
                    }
                    else if(arr[i][j+1] != arr[i][j]) continue;
                }
    else if(dir == 'd')
        for(int j = 0; j < 4; ++j)
            for(int k = 0; k < 4; ++k)
                for(int i = 2; i >= 0; --i){
                    if(arr[i][j] == 0) continue;
                    else if(arr[i][j] == arr[i+1][j]){
                        arr[i+1][j] *= 2;
                        arr[i][j] = 0;
                        sum += arr[i+1][j];
                    }
                    else if(arr[i+1][j] == 0){
                        arr[i+1][j] = arr[i][j];
                        arr[i][j] = 0;
                    }
                    else if(arr[i][j] != arr[i+1][j]) continue;
                }
    else if(dir == 'u')
        for(int j = 0; j < 4; ++j)
            for(int k = 0; k < 4; ++k)
                for(int i = 1; i < 4; ++i){
                    if(arr[i][j] == 0) continue;
                    else if(arr[i][j] == arr[i-1][j]){
                        arr[i-1][j] *= 2;
                        arr[i][j] = 0;
                        sum += arr[i-1][j];
                    }
                    else if(arr[i-1][j] == 0){
                        arr[i-1][j] = arr[i][j];
                        arr[i][j] = 0;
                    }
                    else if(arr[i][j] != arr[i-1][j]) continue;
                }
    return sum;
}
bool Bond::full() const{
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(arr[i][j] == 0) return false;
        }
    }
    return true;
}

bool Bond::lose() const{
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 3; ++j){
            if(arr[i][j] == arr[i][j+1]) return false;
        }
    }
    for(int j = 0; j < 4; ++j){
        for(int i = 0; i < 3; ++i){
            if(arr[i][j] == arr[i+1][j]) return false;
        }
    }
    return true;
}

Game::Game(){
    start = time(NULL);
    cout << "Welcome to the game of 2048!" << endl;
    random(1);
    int count = 0;
    while(++count){
        if(bon.full()){
            if(bon.lose()) break;
        }
        else{
            if(count == 1) random(1);
            else random(0);
        }
        print();
        cout << "Your score: " << score() << endl;
        cout << "(¡ü:u) (¡ý:d) (¡û:l) (¡ú:r) (quit:q): ";
        char ch;
        while(cin >> ch){
            if(ch == 'u' || ch == 'd' || ch == 'l' || ch == 'r' || ch == 'q') break;
        }
        if(ch == 'q') break;
        else{
            int sum = move(ch);
            add_s(sum);
        }
    }
}

Game::~Game(){
    ofstream file("game2048.csv", ofstream::app);
    finall = time(NULL);
    cout << "Game Over" << endl;
    string cstr(std::ctime(&start));
    for(string::size_type i = 0; cstr[i] != '\n'; ++i){
        file << cstr[i];
    }
    file << "," << finall - start << "," << score() << endl;
}