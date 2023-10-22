#include "median.h"
#include "Student_info.h"
#include "grade.h"
// write your code

inline double grade(double midterm, double finall, double homework){
    return 0.2 * midterm + 0.4 * finall + 0.4 * homework;
}

double grade(double midterm, double finall , std::vector<double> homework){
    return grade(midterm, finall, median(homework));
}

double grade(const Core& s){
    return s.grade();
}