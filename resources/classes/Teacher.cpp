//
// Created by hima1 on 5/16/2024.
//

#include "Teacher.h"

Teacher::Teacher(string Name, string Email, string Password, string Code, float Salary)
        : User(TeacherIDCounter++, Name, Email, Password){
    courseCode = Code, salary = Salary;
}

Teacher::Teacher(int ID, string Name, string Email, string Password, string Code, float Salary)
        : User(ID, Name, Email, Password){
    courseCode = Code, salary = Salary;
}

void Teacher::login() {
    int choice = readMenu({"view all info", "show students", "manage grade", "modify info", "Exit"}, "choose an option...");
    switch (choice)
    {
        case 1: {
            cout << "The course code is: " << courseCode << endl;
            cout << "Name is: " << get_name() << endl;
            cout << "The email is: " << get_email() << endl;
            cout << "your password is: " << get_password() << endl;
            cout << "the salary is:" << salary << endl;
            break;
        }
        case 2: {
            printStudentSheet();
            break;
        }
        case 3: {
            int id, points;
            cout << "Enter the id of student you want to change" << endl;
            cin >> id;
            cout << "Enter the new points" << endl;
            changeGradeOfStudent(id, points);
            cout << "The info changed successfully." << endl;
            break;
        }
        case 4: {
            modifyInfo();
            break;
        }
        case 5:
            break;
    }
}

void Teacher::changeGradeOfStudent(int studentID, int points) {
    auto s = students.find(studentID);
    s->second.changeCoursePoints(courseCode, points);
}

string Teacher::getCourseCode() {
    return courseCode;
}

float Teacher::getSalary() {
    return salary;
}

void Teacher::setSalary(float Salary) {
    salary = Salary;
}

vector<Student> Teacher::studentsSheet() {
    vector <Student> studentsSheet;
    /* classes
     *
     * first, second
     * course code, course
     * key  , value
     * classes.find(courseCode)->second
     */
    Course TeacherCourse = courses.find(courseCode)->second;
    /*
     * classe
     * code, title, vector int(student id).
     */

    for(auto &studentID : TeacherCourse.getStudentIDs()){
        // course code
        /*
         * key , value
         * sid , stduent
         * students.find(studentID)->second
         */
        studentsSheet.push_back(students.find(studentID)->second);
    }
    return studentsSheet;
}



void Teacher::printStudentSheet()
{
    vector<Student> students_sheet = studentsSheet();
    for (int i = 0; i < students_sheet.size(); i++)
    {
        cout << students_sheet[i].get_name() << endl;
    }
}

void Teacher::modifyInfo()
{
    int choice = readMenu({"Name", "Email", "Password"}, "Modify Info");
    switch (choice) {
        case 1: {
            cout << "Enter the new name" << endl;
            string Name;
            cin >> Name;
            setName(Name);
            break;
        }
        case 2: {
            cout << "Enter the new email" << endl;
            string Email;
            cin >> Email;
            setEmail(Email);
            break;
        }
        default: {
            cout << "Enter the new password";
            string pass;
            cin >> pass;
            setPassword(pass);
        }
    }
}



