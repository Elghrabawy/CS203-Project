//
// Created by hima1 on 5/16/2024.
//

#ifndef OOP_PROJECT_TEACHER_H
#define OOP_PROJECT_TEACHER_H

#include <iostream>
#include "User.h"
#include "Global.h"
#include "Course.h"
#include "Student.h"

using namespace std;

static int TeacherIDCounter = 1;

class Teacher : public User{
private:
    string courseCode;
    float salary;
public:
    map<int, Student> students;
    map<string, Course> courses; // course code - course

    Teacher(int id, string Name, string Email, string Password, string Code, float Salary);
    Teacher(string Name, string Email, string Password, string Code, float Salary);
    // return course code
    string getCourseCode();

    // return teacher salary
    float getSalary();

    // change teacher salary
    void setSalary(float Salary);

    // manage grades- get student id and his new points.
    void changeGradeOfStudent(int studentID, int points);

    // return vector of students
    vector<Student> studentsSheet();

    // print all students and its points in own course.
    void printStudentSheet();

    // manage grade of student
    void manageGrade();

    // modify teacher informations
    void modifyInfo();


    // display teacher interface
    void login() override;
};

#endif //OOP_PROJECT_TEACHER_H