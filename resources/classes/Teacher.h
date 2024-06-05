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

// Counter for teacher IDs
static int TeacherIDCounter = 1;

/**
 * Teacher class, inheriting from User
 */
class Teacher : public User{
private:
    string courseCode; // Course code that the teacher is teaching
    float salary; // Salary of the teacher
public:
    /**
     * Constructor with ID, name, email, password, course code, and salary
     */
    Teacher(int id, string Name, string Email, string Password, string Code, float Salary);

    /**
     * Constructor with name, email, password, course code, and salary
     */
    Teacher(string Name, string Email, string Password, string Code, float Salary);

    /**
     * Getter for course code
     */
    string getCourseCode();

    /**
     * Getter for teacher salary
     */
    float getSalary();

    /**
     * Setter for teacher salary
     */
    void setSalary(float Salary);

    /**
     * Method to change grade of a student
     * @param studentID - ID of the student
     * @param points - Points to be changed
     * @return - True if the operation was successful, false otherwise
     */
    bool changeGradeOfStudent(int studentID, int points);


    /**
     * Method to print all students and their points in own course
     */
    void printStudentSheet();

    /**
     * Method to manage grade of a student
     */
    void manageGrade();

    /**
     * Method to modify teacher information
     */
    void modifyInfo();

    /**
     * Method for teacher menu
     */
    bool teacherMenu();

    /**
     * Method to view teacher information
     */
    void viewInfo();

    /**
     * Override login method from User
     */
    void login() override;

    /**
     * Method to check if the teacher instance is valid
     */
    bool is();
};

#endif //OOP_PROJECT_TEACHER_H