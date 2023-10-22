#include "median.h"
#include "Student_info.h"
#include "grade.h"
// write your code
#include <string>

inline double grade(double midterm, double finall, double homework){
    return 0.2 * midterm + 0.4 * finall + 0.4 * homework;
}

double grade(double midterm, double finall ,vector<double> homework){
    return grade(midterm, finall, median(homework.begin(), homework.end()));
}

double grade(const Core& s){
    return s.grade();
}

std::string letter_grade(double a){
    const double range[10] = {90, 85, 82, 78, 75, 71, 66, 62, 60, 0};
    const std::string letter[10] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D","F"};
    for(int i = 0; i < 10; ++i){
        if(a >= range[i]) return letter[i];
    }
    return letter[9];
}
