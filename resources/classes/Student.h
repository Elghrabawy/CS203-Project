//
// Created by hima1 on 5/16/2024.
//

#ifndef OOP_PROJECT_STUDENT_H
#define OOP_PROJECT_STUDENT_H

#include "User.h"
#include "Enrollment.h"
#include "Course.h"
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Global.h"
//#include "DB.h"
#include <map>

using namespace std;

static int studentIDCounter = 1;
class Student : public User{
private:
    vector<Enrollment> enrollments;
public:
    map<string, Course> courses; // course code, Course

    Student(int ID, string Name, string Email, string Password, vector <Enrollment> Enrollments);

    Student(string Name, string Email, string Password, vector <Enrollment> Enrollments);

    vector<Enrollment> get_enrollments();

    // enroll new course.
    void enrollNewCourse(string courseCode);

    // return enrolled courses;
    vector <Course> enrolledCourses();

    // change points of this course
    void changeCoursePoints(string courseCode, int points);

    // return gpa of student
    float calcGPA();

    string getTotalGrade();

    // modify student info
    void modifyInfo();

    // view all enrolled courses
    void viewEnrolledCourses();

    // view student info
    void viewInfo();


    bool studentMenu();

    // display student interface
    void login() override;

    bool is();
};


#endif //OOP_PROJECT_STUDENT_H
