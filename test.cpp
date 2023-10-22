#include <iostream>
#include <string>

using namespace std;

int sizeofarr(int a[]){
    return sizeof(a) / sizeof(a[0]);
}

template<class T>
class vector{
    public:
        vector(){
            arr = new T[1];
            len = 0;
            capacity = 1;
        }
        ~vector(){
            delete[] arr;
        }
        void push_back(T){
            if(len == capacity){
                capacity *= 2;
                T *t = new T[capacity];
                for(int i = 0; i < len; ++i){
                    t[i] = arr[i];
                }
                delete[] arr;
                arr = t;
            }
            arr[len++] = t;
        }
        void pop_back(){
            --len;
        }
        T& operator[](int){
            return arr[i];
        }
        int size(){
            return len;
        }
    private:
        T *arr;
        int len;
        int capacity;
};
int main(){
    vector<int> vec;
    for(int i = 1; i <= 5; ++ i){
        vec.push_back(i);
    }
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << " ";
    }
    return 0;
}