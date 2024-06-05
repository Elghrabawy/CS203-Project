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

void Student::enrollNewCourse(string courseCode) {
    enrollments.push_back(Enrollment(courseCode, -1));
    DB::addNewEnrollment(courseCode, id);
    cout << colored("Added Successfully...", "\033[1;32m") << endl;
}

void Student::changeCoursePoints(string courseCode, int points) {
    bool exist = DB::modifyEnrollment(id, courseCode, points);
    if(!exist){
        cout << "This course not exists" << endl;
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

void Student::modifyInfo() {
    int choose = readMenu2({
                                   "Modify name",
                                   "Modify password",
                                   "Modify email"
                           },
                           "choose one option: ");
    switch (choose) {
        case 1:{
            string Name;
            cout << "Enter Modifying Name : ";
            cin >> Name;
            setName(Name);
            DB::modifyStudentInfo(id, Name, DB::fields::_NAME);
            break;
        }
        case 2:{
            string Password;
            cout << "Enter Modifying Password : ";
            cin >> Password;
            setPassword(Password);
            DB::modifyStudentInfo(id, Password, DB::fields::_PASSWORD);
            break;
        }
        case 3:{
            string Email;
            cout << "Enter Modifying Email : ";
            cin >> Email;
            setEmail(Email);
            DB::modifyStudentInfo(id, Email, DB::fields::_EMAIL);
            break;
        }
    }
}

void Student::viewEnrolledCourses() {
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
}

void Student::viewInfo() {
    tableHeader({"ID", to_string(id)}, 21, 16);
    tableHeader({"Name", name}, 21, 16);
    tableHeader({"Email", email}, 21, 16);
    tableHeader({"Password", password}, 21, 16);
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
            vector<string> notEnrolledCourses = DB::getNotEnrolledCourses(id);
            if(notEnrolledCourses.empty()){
                cout << colored("No Courses to enroll", "\033[1;31m") << endl;
                pauseScreen();
                break;
            }
            else{
                int choose = readMenu2(notEnrolledCourses, "Choose the number of course to enroll: ");
                if(choose == -1){
                    pauseScreen();
                    break;
                }
                else{
                    enrollNewCourse(notEnrolledCourses[choose - 1]);
                    pauseScreen();
                }
            }
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
            viewInfo();
            pauseScreen();
            break;
        }
        case 4:
        {
            system("cls");
            header("VIEW ENROLLED COURSES");
            viewEnrolledCourses();
            pauseScreen();
            break;
        }
        case 5:
        {
            system("cls");
            header("MODIFY INFO");
            modifyInfo();
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





