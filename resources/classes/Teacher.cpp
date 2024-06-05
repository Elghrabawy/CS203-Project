//
// Created by hima1 on 5/16/2024.
//

#include "Teacher.h"
#include "DB.h"

Teacher::Teacher(string Name, string Email, string Password, string Code, float Salary)
        : User(TeacherIDCounter++, Name, Email, Password) {
    courseCode = Code, salary = Salary;
}

Teacher::Teacher(int ID, string Name, string Email, string Password, string Code, float Salary)
        : User(ID, Name, Email, Password) {
    courseCode = Code, salary = Salary;
}

void Teacher::login() {
    while (teacherMenu());
}



bool Teacher::teacherMenu() {
    system("cls");
    int choice = readMenu(
            {"view all info",
             "show students",
             "manage grade",
             "modify info", "Exit"
            },
            "choose an option...");
    switch (choice) {
        case 1: {
            system("cls");
            header("TEACHER INFOREMTION");
            viewInfo();
            pauseScreen();
            break;
        }
        case 2: {
            system("cls");
            header("STUDENTS SHEET");
            printStudentSheet();
            pauseScreen();
            break;
        }
        case 3: {
            system("cls");
            header("MANAGE GRADES");
            int studentID, points;

            printStudentSheet();
            cout << "Enter the id of student you want to change: ";
            cin >> studentID;
            cout << "Enter the new points: ";
            cin >> points;
            bool done = changeGradeOfStudent(studentID, points);
            if(done)
                cout << colored("The info changed successfully", Colors::green) << endl;
            else
                cout << colored("The info didn't change successfully.", Colors::red) << endl;
            pauseScreen();
            break;
        }
        case 4: {
            system("cls");
            modifyInfo();
            pauseScreen();
            break;
        }
        case 5:{
            system("cls");
            return false;
        }
    }
    return true;
}

bool Teacher::changeGradeOfStudent(int studentID, int points) {
    if(points < 0 || points > 100) {
        cout << "Invalid points" << endl;
        return false;
    }
    return DB::modifyEnrollment(studentID, courseCode, points);
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

void Teacher::printStudentSheet() {
    vector<pair<Student, Enrollment>> students = DB::getStudentsOfTeacher(get_id());
    tableHeader(
            {
                make_pair("ID", 6),
                make_pair("Name", 24),
                make_pair("Points", 10)
            },
            17);
    for(auto &[student, enrollment] : students){
        tableData(
            {
                make_pair(to_string(student.get_id()), 6),
                make_pair(student.get_name(), 24),
                make_pair(enrollment.get_points() != -1 ? to_string(enrollment.get_points()) : "Pending", 10)
            },
            17
            );
    }
    tableFooter({6, 24, 10}, 17);
}

void Teacher::modifyInfo() {
    int choice = readMenu({"Name", "Email", "Password"}, "Modify Info");
    switch (choice) {
        case 1: {
            cout << "Enter the new name" << endl;
            string Name;
            cin >> Name;
            setName(Name);
            DB::modifyTeacher(get_id(), Name, DB::fields::_NAME);
            break;
        }
        case 2: {
            cout << "Enter the new email" << endl;
            string Email;
            cin >> Email;
            setEmail(Email);
            DB::modifyTeacher(get_id(), Email, DB::fields::_EMAIL);
            break;
        }
        default: {
            cout << "Enter the new password";
            string Password;
            cin >> Password;
            setPassword(Password);
            DB::modifyTeacher(get_id(), Password, DB::fields::_PASSWORD);
        }
    }
}

void Teacher::viewInfo() {
    tableHeader({make_pair("ID", 12), make_pair(to_string(id), 29)}, 17);
    tableHeader({make_pair("Name", 12), make_pair(name, 29)}, 17);
    tableHeader({make_pair("Email", 12), make_pair(email, 29)}, 17);
    tableHeader({make_pair("course Code", 12), make_pair(courseCode, 29)}, 17);
    tableHeader({make_pair("Password", 12), make_pair(password, 29)}, 17);
}



