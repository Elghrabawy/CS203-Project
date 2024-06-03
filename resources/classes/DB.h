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
    /**
     * Enum to represent the fields in the database.
     */
    enum fields{_NAME, _EMAIL, _PASSWORD, _GRADE, _SALARY, _CODE, _TITLE};

    /**
     * Default constructor for the DB class.
     */
    DB();

    /********** Students table functions **********/
    /**
     * Function to get a student object by student id.
     * @param id - The id of the student.
     * @return - The student object if found, else an empty student object.
     */
    static Student getStudent(int id);

    /**
     * Function to get all students as objects.
     * @return - A vector of student objects.
     */
    static vector<Student> getAllStudents();

    /**
     * Function to modify student name in db, return false if not exist student.
     * @param id - The id of the student.
     * @param value - The new value for the field.
     * @param field - The field to be modified.
     * @return - True if the operation was successful, false otherwise.
     */
    static bool modifyStudentInfo(int id, string value, fields field);

    /**
     * Function to add a new student in the database.
     * @param name - The name of the student.
     * @param email - The email of the student.
     * @param password - The password of the student.
     * @return - The id of the new student.
     */
    static int addNewStudent(string name, string email, string password);


    /********** Teachers table functions **********/
    /**
     * Function to get a teacher object by teacher id.
     * @param id - The id of the teacher.
     * @return - The teacher object if found, else an empty teacher object.
     */
    static Teacher getTeacher(int id);

    /**
   * Function to get all teachers as objects.
   * @return - A vector of teacher objects.
   */
    static vector<Teacher> getAllTeachers();


    /**
     * Function to modify teacher information in db, return true if modified else return zero if has problem line can't find teacher or invalid input.
     * @param id - The id of the teacher.
     * @param value - The new value for the field.
     * @param field - The field to be modified.
     * @return - True if the operation was successful, false otherwise.
     */
    static bool modifyTeacher(int id, string value, fields field);
    static bool modifyTeacher(int id, float value, fields field);

    /**
    * Function to add a new teacher in the database.
    * @param name - The name of the teacher.
    * @param email - The email of the teacher.
    * @param password - The password of the teacher.
    * @param courseCode - The course code of the teacher.
    * @param salary - The salary of the teacher.
    * @return - The id of the new teacher.
    */
    static int addNewTeacher(string name, string email, string password, string courseCode, float salary);


    /********** Enrollments table functions **********/
    /**
     * Function to add a new enrollment in the database.
     * @param code - The code of the course.
     * @param studentID - The id of the student.
     * @return - The id of the new enrollment.
     */
    static int addNewEnrollment(string code, int studentID);
    /**
     * Function to modify the points of an enrollment.
     * @param studentID - The id of the student.
     * @param courseCode - The code of the course.
     * @param points - The new points for the enrollment.
     * @return - True if the operation was successful, false otherwise.
     */
    static bool modifyEnrollment(int studentID, string courseCode, int points);


    /********** Courses table functions **********/
    /**
    * Function to get a course object by course code.
    * @param code - The code of the course.
    * @return - The course object.
    */
    static Course getCourse(string code);
    /**
     * Function to get all courses as objects.
     * @return - A vector of course objects.
     */
    static vector<Course> getAllCourses();
};


#endif //EDUCATIONAL_MS_DB_H
