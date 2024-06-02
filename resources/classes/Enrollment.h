//
// Created by hima1 on 5/16/2024.
//

#ifndef OOP_PROJECT_ENROLLMENT_H
#define OOP_PROJECT_ENROLLMENT_H

#include <iostream>
#include <string>


using namespace std;

class Enrollment {
private:
    int studentID;
    string courseCode;
    int points;
public:
    Enrollment(string Code, int Points);
    Enrollment(int StudentID, string Code, int Points);
    string get_code();
    int get_points();
    string get_grade();
    void set_points(int Points);
};


#endif //OOP_PROJECT_ENROLLMENT_H
