//
// Created by hima1 on 5/16/2024.
//

#ifndef OOP_PROJECT_ADMIN_H
#define OOP_PROJECT_ADMIN_H

#include <iostream>
#include <cmath>
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Global.h"


using namespace std;


class Admin  : public User {
public:
    map<int, Student> students;
    map<int, Teacher> teachers;
    map<string, Course> courses;

    Admin(int id , string email, string name , string pass );
    void addStudent (string Name, string Email, string Password);
    void removeStudent (int);
    void addTeacher(string Name, string Email, string password, string courseCode, double salary);
    void removeTeacher(int);
    void addCourse (string courseCode, string courseTitle);
    void removeCourse(string);


    void printAllStudents();
    void printAllTeachers();
    void printAllCourses();
    void adminMenu();
//    void login() override;
};

#endif //OOP_PROJECT_ADMIN_H
