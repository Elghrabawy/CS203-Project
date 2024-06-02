//
// Created by hima1 on 5/16/2024.
//

#include "Student.h"
#include "DB.h"

Student::Student(string Name, string Email, string Password, vector<Enrollment> Enrollments)
    : User(studentIDCounter++, Name, Email, Password){
    enrollments = Enrollments;
}

Student::Student(int ID, string Name, string Email, string Password, vector<Enrollment> Enrollments)
    : User(ID, Name, Email, Password){
    enrollments = Enrollments;
}



void Student::login() {
    while(studentMenu()) continue;
}

vector<Enrollment> Student::get_enrollments() {
    return enrollments;
}

vector<Course> Student::enrolledCourses() {
    vector <Course> Enrolledcourses;
//    for(int i = 0; i < enrollments.size(); i++){
//        Enrolledcourses.push_back(courses.find(enrollments[i].get_code())->second);
//    }

    for(auto &enroll : enrollments){
        Enrolledcourses.push_back(DB::getCourse(enroll.get_code()));
    }
    return Enrolledcourses;
}

void Student::enrollNewCourse(string courseCode) {
    enrollments.push_back(Enrollment(courseCode, -1));
    DB::addNewEnrollment(courseCode, id);
    cout << colored("Added Successfully...", "\033[1;32m") << endl;
}

void Student::changeCoursePoints(string courseCode, int points) {
    // without db
    int idx = -1;
    for(int i = 0; i < enrollments.size(); i++){
        if(enrollments[i].get_code() == courseCode){
            idx = i;
            break;
        }
    }
    if(idx != -1){
        enrollments[idx].set_points(points);
    }
    else{
        cout << "this course not exists" << endl;
    }

    // with_db
    bool exist = DB::modifyEnrollment(id, courseCode, points);
    if(!exist){
//        cout << "This course not exists" << endl;
    }
}

float Student::calcGPA() {
    float totalPoints = 0, countCourses = enrollments.size();
    for(auto &enrollment : enrollments){
        totalPoints += enrollment.get_points();
    }

    return (totalPoints / (100 * countCourses)) * 4;
}

string Student::getTotalGrade() {
    float GPA = calcGPA();
    if(GPA >= 3.8){
        return "A+";
    }else if(GPA >= 3.6){
        return "A";
    }else if(GPA >= 3.4){
        return "A-";
    }else if(GPA >= 3.2){
        return "B+";
    }else if(GPA >= 3){
        return "B";
    }else if(GPA >= 2.8){
        return "C+";
    }else if(GPA >= 2.6){
        return "C";
    }else if(GPA >= 2.4){
        return "D+";
    }else if(GPA >= 2.2){
        return "D";
    }else if(GPA >= 2){
        return "D-";
    }else{
        return "F";

    }
}

bool Student::studentMenu()
{
    system("cls");
    int choice = readMenu(
            { "Enroll new course",
              "Show GPA",
              "View All Info",
              "View Enrolled courses",
              "Modify Info",
              "Main Menu"
            },
            "Student Menu");

    switch (choice)
    {
        case 1:
        {
            system("cls");
            header("ENROLL NEW COURSE");
            string code;
            cout << "Enter Your Code : ";
            cin >> code;
            enrollNewCourse(code);
            pauseScreen();
            break;
        }
        case 2:
        {
            system("cls");
            header("SHOW GPA");
            cout << calcGPA() << endl;
            pauseScreen();
            break;
        }
        case 3:
        {
            system("cls");
            header("VIEW ALL INFO");
            cout << "Name : " << name << endl;
            cout << "ID    : " << id << endl;
            cout << "E-mail : " << email << endl;
            cout << "Password : " << password << endl;
            pauseScreen();
            break;
        }
        case 4:
        {
            system("cls");
            header("VIEW ENROLLED COURSES");
            cout << "                      ";
            cout << "+" << string(15, '-') << "+" << string(15, '-') << "+" << endl;
            cout << "                      ";
            cout << "|" << printAlign("course code", CENTER, 15) << "|" << printAlign("grade", CENTER, 15) << "|" << endl;
            cout << "                      ";
            cout << "+" << string(15, '-') << "+" << string(15, '-') << "+" << endl;
            for (auto &e : enrollments)
            {
                string course_code = e.get_code();
                string grade = e.get_grade();
                cout << "                      ";
                cout << "|" << printAlign(course_code, CENTER, 15) << "|" << printAlign(grade, CENTER, 15) << "|" << endl;

            }
            cout << "                      ";
            cout << "+" << string(15, '-') << "+" << string(15, '-') << "+" << endl;

            if(enrollments.size() == 0){
                cout << colored("No Enrolled Courses", "\033[1;31m");
            }

            pauseScreen();

            break;
        }
        case 5:
        {
            system("cls");
            header("MODIFY INFO");
            int choose = readMenu2({
                "Modify name",
                "Modify password",
                "Modify email"
            },
                                   "choose one option: ");
            switch (choose) {
                case 1:{
                    string n;
                    cout << "Enter Modifying Name : ";
                    cin >> n;
                    setName(n);
                    break;
                }
                case 2:{
                    string p;
                    cout << "Enter Modifying Password : ";
                    cin >> p;
                    setPassword(p);
                    break;
                }
                case 3:{
                    string e;
                    cout << "Enter Modifying Email : ";
                    cin >> e;
                    setEmail(e);
                }
            }
            pauseScreen();
            break;
        }
        case 6:{
            return false;
            break;
        }
    }
    return true;
}

bool Student::is() {
    return ((name != "NULL") && (email != "NULL") && (password != "NULL"));
}

