#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H

#include <iostream>
#include <cstring>

using std::string;
using std::cin;
using std::cout;
using std::endl;

const int MAX_LENGTH_NAME = 20;

class Student {
public:
    void takeData();

    void showData();

private:
    int mAdmissionNumber;
    char mStudentName[MAX_LENGTH_NAME + 1];
    float mEng;
    float mMath;
    float mScience;
    float mTotal;

    float mCalculateTotal();
};

#endif //STUDENT_STUDENT_H
