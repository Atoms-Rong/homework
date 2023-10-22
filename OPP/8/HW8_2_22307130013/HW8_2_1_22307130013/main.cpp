#include <iostream>
#include <vector>
#include "shape.h"
#include <fstream>
#include <algorithm>
#include <iomanip>

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::setprecision;

int main(){
    vector<Shape*> shapes;
    Shape* record;
    char ch;
    ifstream infile("shapes");
    while(infile >> ch){
        if(ch == 'T'){
            record = new Triangle(infile);
        }
        else if(ch == 'C'){
            record = new Circle(infile);
        }
        else if(ch == 'R'){
            record = new Rectangle(infile);
        }
        shapes.push_back(record);
    }
    sort(shapes.begin(), shapes.end(), compare);
    cout << endl << "Area" << "\t" << "Perimeter" << endl;
    for(vector<Shape*>::size_type i = 0; i != shapes.size(); ++i){
        if(shapes[i]->area() == 0) continue;
        cout << setprecision(3) << shapes[i]->area() << "\t" << shapes[i]->circle() << endl;
        delete shapes[i];
    }
    return 0;
}