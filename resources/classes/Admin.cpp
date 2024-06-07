
#include "Admin.h"
#include "DB.h"
#include "Global.h"

using namespace std;

void displayFooter() {
    cout << "\033[1;33m"; // Set text color to yellow
    header("Powerd by One More Trie");
    cout << "\033[0m"; // Reset text color
}

Admin::Admin(int id, string email, string name, string pass)
        : User(id, name, email, pass) {
}

void Admin::addStudent(string Name, string Email, string Password) {
    int id = DB::addNewStudent(Name, Email, Password);
    cout << colored("Student Added Successfully", Colors::green) << endl;
    cout << "Student ID: " << id << endl;
}

void Admin::removeStudent(int id) {
    bool remove = DB::removeStudent(id);
    if (remove) {
        cout << colored("Deleted student of id: " + to_string(id), Colors::green) << endl;
    } else {
        cout << colored("Student of ID " + to_string(id) + " not found", Colors::red) << endl;
    }
}

void Admin::addTeacher(string Name, string Email, string Password, string courseCode, double salary) {
    int id = DB::addNewTeacher(Name, Email, Password, courseCode, salary);
    cout << colored("Teacher Added Successfully", Colors::green) << endl;
    cout << "Teacher ID: " << id << endl;
}

void Admin::removeTeacher(int id) {
    bool remove = DB::removeTeacher(id);
    if (remove) {
        cout << colored("Deleted teacher of id: " + to_string(id), Colors::green) << endl;
    } else {
        cout << colored("Teacher of ID " + to_string(id) + " not found", Colors::red) << endl;
    }
}

void Admin::addCourse(string courseCode, string courseTitle) {
    bool inserted = DB::addNewCourse(courseCode, courseTitle);
    cout <<
         (
                 inserted ?
                 colored("Course Added Successfully", Colors::green) :
                 colored("Can't Add Course .. maybe the course already exist", Colors::red)
         )
         << endl;
}

void Admin::printAllStudents() {
    vector<Student> students = DB::getAllStudents();
    if (students.empty()) {
        cout << "No students found!" << endl;
    } else {
        tableHeader({make_pair("ID", 10), make_pair("Name", 20)}, 23);
        for (auto student: students) {
            tableData(
                    {
                            make_pair(to_string(student.get_id()), 10),
                            make_pair(student.get_name(), 20)
                    }, 23);
        }
        tableFooter({10, 20}, 23);
    }
}

void Admin::printAllTeachers() {
    vector<Teacher> teachers = DB::getAllTeachers();
    if (teachers.empty()) {
        cout << "No teachers found!" << endl;
    } else {
        tableHeader({make_pair("ID", 10), make_pair("Name", 20)}, 23);
        for (auto teacher: teachers) {
            tableData(
                    {
                            make_pair(to_string(teacher.get_id()), 10),
                            make_pair(teacher.get_name(), 20)
                    }, 23);
        }
        tableFooter({10, 20}, 23);
    }
}

void Admin::printAllCourses() {
    vector<Course> courses = DB::getAllCourses();
    if (courses.empty()) {
        cout << "No courses found!" << endl;
    } else {
        tableHeader({make_pair("Code", 10), make_pair("Name", 20)}, 23);
        for (auto course: courses) {
            tableData(
                    {
                            make_pair(course.get_code(), 10),
                            make_pair(course.get_title(), 20)
                    }, 23);
        }
        tableFooter({10, 20}, 23);
    }
}

bool Admin::adminMenu() {
    int choice;
    clearScreen();
    choice = readMenu(
            {"Login",
             "Add Student",
             "Remove Student",
             "Add Teacher",
             "Remove Teacher",
             "Add Course",
             "Remove Course",
             "Print All Students",
             "Print All Teachers",
             "Print All Courses",
             "Exit"
            },
            "Admin Menu"
    );

    // Ensure any remaining input is cleared
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clearScreen();
    switch (choice) {
        // add Student
        case 2: {
            string name, email, password;
            cout << "Enter student name : ";
            cin >> name;
            cout << "Enter student email : ";
            cin >> email;
            cout << "Enter student password : ";
            cin >> password;

            addStudent(name, email, password);
            break;
        }
            // remove student
        case 3: {
            printAllStudents();
            int id;
            cout << "Enter student ID to remove: ";
            cin >> id;
            removeStudent(id);
            break;
        }
            // add teacher
        case 4: {
            string name, email, password, code;
            float salary;

            cout << "\nEnter student name : ";
            cin >> name;
            cout << "\nEnter student email : ";
            cin >> email;
            cout << "\nEnter student password : ";
            cin >> password;
            cout << "\nEnter course code : ";
            cin >> code;
            cout << "\nEnter salary : ";
            cin >> salary;

            addTeacher(name, email, password, code, salary);
            break;
        }
            // remove teacher
        case 5: {
            int id;
            cout << "Enter teacher ID to remove: ";
            cin >> id;
            removeTeacher(id);
            break;
        }
            // add course
        case 6: {
            string code, name;
            cout << "Enter course ID and name: ";
            cin >> code >> name;
            addCourse(code, name);
            break;
        }
            // remove course
        case 7: {
            string id;
            cout << "Enter course ID to remove: ";
            cin >> id;
            removeCourse(id);
            break;
        }
            // print all students
        case 8:
            printAllStudents();
            break;
            // print all teachers
        case 9:
            printAllTeachers();
            break;
            // print all courses
        case 10:
            printAllCourses();
            break;
        case 11:
            cout << "\033[1;31m> Exiting the program.\033[0m\n";
            return false;
        default:
            cout << "\033[1;31m> Invalid choice. Please select a valid option.\033[0m\n";
            return false;
    }
    pauseScreen();
    return true;
}

void Admin::removeCourse(string) {
    cout << colored("Will be implemented in the future\n", Colors::yellow);

}

void Admin::login() {
    while(adminMenu());
}

