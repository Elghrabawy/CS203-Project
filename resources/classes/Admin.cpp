
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

void Admin::addStudent(Student s) {
    auto it = students.find(s.get_id());
    if (it == students.end()) {
        students.insert({s.get_id(), s});
        cout << "Student Added Successfully \n";
    } else {
        cout << "Student with id " << s.get_id() << " exists , please try again \n";
    }
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

void Admin::addTeacher(Teacher t) {
    auto it = teachers.find(t.get_id());
    if (it == teachers.end()) {
        teachers.insert({t.get_id(), t});
        cout << "Teacher Added Successfully \n";
    } else {
        cout << "Teacher with id " << t.get_id() << " exists , please try again \n";
    }
}

void Admin::removeTeacher(int id) {
    auto it = teachers.find(id);
    if (it != teachers.end()) {
        teachers.erase(it);
        cout << "Deleted teacher-id: " << id << endl;
    } else {
        cout << "Teatcher of ID " << id << "not found \n" << endl;
    }
}

void Admin::addCourse(Course c) {
    auto it = courses.find(c.get_code());
    if (it == courses.end()) {
        courses.insert({c.get_code(), c});
        cout << "New Course Added Successfully \n";
    } else {
        cout << "Invalid Course Code , please try again \n";
    }
}

void Admin::removeCourse(string c) {
    auto it = courses.find(c);
    if (it != courses.end()) {
        courses.erase(it);
        cout << "Deleted Course Code : " << c << endl;
    } else {
        cout << "Course of Code " << c << "not found \n" << endl;
    }
}

void Admin::printAllStudents() {
    if (students.empty()) {
        cout << "No students found!" << endl;
    } else {
        tableHeader({"ID", "Name"}, 15, 23);
        for (auto it: students) {
//            cout << "ID: " << it.first << ", Name: " << it.second.get_name() << endl;
            tableData({to_string(it.first), it.second.get_name()}, 15, 23);
        }
        tableFooter(2, 15, 23);
    }
}

void Admin::printAllTeachers() {
    if (teachers.empty()) {
        cout << "No teachers found!" << endl;
    } else {
        tableHeader({"ID", "Name"}, 15, 23);
        for (auto it: students) {
//            cout << "ID: " << it.first << ", Name: " << it.second.get_name() << endl;
            tableData({to_string(it.first), it.second.get_name()}, 15, 23);
        }
        tableFooter(2, 15, 23);
    }
}

void Admin::printAllCourses() {
    if (courses.empty()) {
        cout << "No courses found!" << endl;
    } else {
        tableHeader({"ID", "Name"}, 15, 23);
        for (auto it: courses) {
//            cout << "ID: " << it.first << ", Name: " << it.second.get_title() << endl;
            tableData({it.first, it.second.get_title()}, 15, 23);
        }
        tableFooter(2, 15, 23);
    }
}

void Admin::adminMenu() {
    int choice;
    do {
        clearScreen();
//        displayLogo();
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

        switch (choice) {
            case 2: {
                string name, email, password;
                cout << "Enter student name : ";
                cin >> name;
                cout << "Enter student email : ";
                cin >> email;
                cout << "Enter student password : ";
                cin >> password;

                addStudent(Student(name, email, password, {}));
                break;
            }
            case 3: {
                int id;
                cout << "Enter student ID to remove: ";
                cin >> id;
                removeStudent(id);
                break;
            }
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

                addTeacher(Teacher(name, email, password, code, salary));
                break;
            }
            case 5: {
                int id;
                cout << "Enter teacher ID to remove: ";
                cin >> id;
                removeTeacher(id);
                break;
            }
            case 6: {
                string code, name;
                cout << "Enter course ID and name: ";
                cin >> code >> name;
                addCourse(Course(code, name));
                break;
            }
            case 7: {
                string id;
                cout << "Enter course ID to remove: ";
                cin >> id;
                removeCourse(id);
                break;
            }
            case 8:
                printAllStudents();
                break;
            case 9:
                printAllTeachers();
                break;
            case 10:
                printAllCourses();
                break;
            case 11:
                cout << "\033[1;31m> Exiting the program.\033[0m\n";
//                saveData();
                return;
            default:
                cout << "\033[1;31m> Invalid choice. Please select a valid option.\033[0m\n";
                break;
        }
        displayFooter();
        pauseScreen();
        clearScreen();
    } while (choice != 11);
}

