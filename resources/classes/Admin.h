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

/**
 * Admin class, inheriting from User
 */
class Admin  : public User {
public:
    map<int, Student> students; // Map of students with student ID as key
    map<int, Teacher> teachers; // Map of teachers with teacher ID as key
    map<string, Course> courses; // Map of courses with course code as key

    /**
     * Constructor with ID, email, name, and password
     */
    Admin(int id , string email, string name , string pass );

    /**
     * Method to add a student
     */
    void addStudent (string Name, string Email, string Password);

    /**
     * Method to remove a student
     */
    void removeStudent (int);

    /**
     * Method to add a teacher
     */
    void addTeacher(string Name, string Email, string password, string courseCode, double salary);

    /**
     * Method to remove a teacher
     */
    void removeTeacher(int);

    /**
     * Method to add a course
     */
    void addCourse (string courseCode, string courseTitle);

    /**
     * Method to remove a course
     */
    void removeCourse(string);

    /**
     * Method to print all students
     */
    void printAllStudents();

    /**
     * Method to print all teachers
     */
    void printAllTeachers();

    /**
     * Method to print all courses
     */
    void printAllCourses();

    /**
     * Method for admin menu
     */
    bool adminMenu();

    /**
     * Override login method from User
     */
    void login() override;
};

#endif //OOP_PROJECT_ADMIN_H