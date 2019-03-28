#include "Student.h"

void Student::takeData() {
    cout << "Type student's admission number, please: ";
    cin >> mAdmissionNumber;
    cout << "Type student's name, please: ";
    string name;
    cin >> name;
    while (name.size() > MAX_LENGTH_NAME) {
        cout << "Type student's name that is no longer than 20, please: ";
        cin >> name;
    }
    for (size_t i = 0; i < name.size(); ++i) {
        mStudentName[i] = name[i];
    }
    mStudentName[name.size()] = '\0';
    cout << "Type student's eng value, please: ";
    cin >> mEng;
    cout << "Type student's math value, please: ";
    cin >> mMath;
    cout << "Type student's science value, please: ";
    cin >> mScience;
    mTotal = mCalculateTotal();
}

void Student::showData() {
    cout << "Admission number: " << mAdmissionNumber << endl
         << "Name: " << mStudentName << endl
         << "Eng: " << mEng << endl
         << "Math: " << mMath << endl
         << "Science: " << mScience << endl
         << "Total: " << mTotal << endl;
}

float Student::mCalculateTotal() {
    return mEng + mMath + mScience;
}
