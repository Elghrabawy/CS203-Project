//
// Created by hima1 on 5/14/2024.
//

#ifndef EDUCATIONAL_MS_DB_H
#define EDUCATIONAL_MS_DB_H


#include <SQLiteCpp/SQLiteCpp.h>
#include <config.h>
#include <string>
#include "classes/Student.h"
#include "classes/Teacher.h"
#include "classes/Course.h"

using namespace std;

class DB {
public:
    enum fields{_NAME, _EMAIL, _PASSWORD, _GRADE, _SALARY, _CODE, _TITLE};


    DB();

    /********** Students table functions **********/
    // return student object by student id
    static Student getStudent(int id);

    // return all students as objects
    static vector<Student> getAllStudents();

    // modify student name in db, return false if not exist student
    static bool modifyStudentInfo(int id, string value, fields field);

    // add new student in database, return id
    static int addNewStudent(string name, string email, string password);


    /********** Teachers table functions **********/
    // return teacher object by teacher id
    static Teacher getTeacher(int id);

    // return all teachers in database
    static vector<Teacher> getAllTeachers();

    // modify teacher information in db, return true if modified else return zero if has problem line can't find teacher or invalid input
    static bool modifyTeacher(int id, string value, fields field);
    static bool modifyTeacher(int id, float value, fields field);

    // add new teacher in database, return id
    static int addNewTeacher(string name, string email, string password, string courseCode, float salary);


    /********** Enrollments table functions **********/
    // add new enrollment in database, return id
    static int addNewEnrollment(string code, int studentID);
    // change point of enrollment
    static bool modifyEnrollment(int studentID, string courseCode, int points);


    /********** Courses table functions **********/
    static Course getCourse(string code);
    static vector<Course> getAllCourses();



};


#endif //EDUCATIONAL_MS_DB_H
