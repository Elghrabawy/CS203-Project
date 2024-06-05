#include <iostream>
#include "classes/Student.h"
#include "classes/Global.h"
#include "classes/Teacher.h"
#include "classes/Admin.h"
#include <map>
#include "classes/DB.h"
#include <unistd.h>

using namespace std;

map<string, Course> courses;
map<int, Student> students;
map<int, Teacher> teachers;
map<int, Admin> admins;

void displayName(string input = "Educational Management System", int speed = 100){
    cout << "                        ";
    for(auto &character : input){
        cout << character;
        usleep(speed * 1000);
    }
    cout << endl << endl;
}

void display_logo(){
    cout << R"(
                 _______ ______   ___ ___     ___ ___ _______
                |   _   |   _  \ |   Y   |   |   Y   |   _   |
                |.  1___|.  |   \|.  |   |   |.      |   1___|
                |.  __)_|.  |    |.  |   |   |. \_/  |____   |
                |:  1   |:  1    |:  1   |   |:  |   |:  1   |
                |::.. . |::.. . /|::.. . |   |::.|:. |::.. . |
                `-------`------' `-------'   `--- ---`-------'
)";
}

int studentLogin() {
    system("cls");
    header("STUDENT LOGIN", "\033[1;31m");
    int id;
    cout << printAlign("Student ID", CENTER, 78) << endl;
    cout << string(78/2 - 5, ' ') << " : ";
    cin >> id;

    Student cur = DB::getStudent(id);
    if(cur.is()) {
        string password;
        cout << printAlign("Student Password", CENTER, 78) << endl;
        cout << string(78 / 2 - 5, ' ') << " : ";
        cin >> password;

        if (cur.get_password() == password)
            return id;
        else {
            return -2;
        }
    }
    else{
        return -1;
    }
}

int teacherLogin(){
    system("cls");
    header("TEACHER LOGIN", "\033[1;31m");

    int id;
    cout << printAlign("Teacher ID", CENTER, 78) << endl;
    cout << string(78/2 - 5, ' ') << " : ";
    cin >> id;

    auto it = teachers.find(id);

    if(it == teachers.end()){
        return -1;
    }

    string password;
    cout << printAlign("Teacher Password", CENTER, 78) << endl;
    cout << string(78/2 - 5, ' ') << " : ";
    cin >> password;

    if(it->second.get_password() == password)
        return id;
    else
        return -2;
}

int adminLogin(){
    system("cls");
    header("ADMIN LOGIN", "\033[1;31m");

    int id;
    cout << printAlign("Admin ID", CENTER, 78) << endl;
    cout << string(78/2 - 5, ' ') << " : ";
    cin >> id;

    auto it = admins.find(id);

    if(it == admins.end()){
        return -1;
    }
    string password;
    cout << printAlign("Admin Password", CENTER, 78) << endl;
    cout << string(78/2 - 5, ' ') << " : ";
    cin >> password;

    if(it->second.get_password() == password)
        return id;
    else
        return -2;
}

void login() {
    int mode, id;
    mode = readMenu(
            {"Student",
             "Teacher",
             "Admin",
             "Exit"}, "Login As"
    );

    switch (mode) {
        case 1:{
            int id = studentLogin();
            if(id == -1){
                cout << colored("This id not exists", "\033[1;31m") << endl;
                pauseScreen();
                system("cls");
                login();
            }
            else if(id == -2){
                cout << colored("Wrong Password", "\033[1;31m") << endl;
                pauseScreen();
                system("cls");
                login();
            }
            else{
                system("cls");
                Student cur = DB::getStudent(id);
                cur.login();
            }

            break;
        }
        case 2:{
            int id = teacherLogin();
            if(id == -1){
                cout << colored("This id not exists", "\033[1;31m") << endl;
                pauseScreen();
                system("cls");
                login();
            }else if(id == -2){
                cout << colored("Wrong Password", "\033[1;31m") << endl;
                pauseScreen();
                system("cls");
                login();
            }else{
                system("cls");
                Teacher &cur = teachers.find(id)->second;
                cur.students = students;
                cur.courses = courses;
                cur.login();
            }
            break;
        }
        case 3:{
            int id = adminLogin();
            if(id == -1){
                cout << colored("This id not exists", "\033[1;31m") << endl;
                pauseScreen();
                system("cls");
                login();
            }
            else if(id == -2){
                cout << colored("Wrong Password", "\033[1;31m") << endl;
                pauseScreen();
                system("cls");
                login();
            }else{
                system("cls");
                Admin &cur = admins.find(id)->second;
                cur.students = students;
                cur.courses = courses;
                cur.teachers = teachers;
                cur.adminMenu();
            }
            break;
        }
    }
}

int main() {
    DB::modifyTeacher(2, "ahmed@gmail.com", DB::_EMAIL);
    cout << "\033[1;31m";
    display_logo();
    displayName();

    Student s1("ibrahim", "ibrahim@gmail.com", "123", {});
    Student s2("ahmed", "ahmed@gmail.com", "123", {});
    Student s3("khaled", "khaled@gmail.com", "123", {});

    students.insert({s1.get_id(), s1});
    students.insert({s2.get_id(), s2});
    students.insert({s3.get_id(), s3});

    Course c1("cs1", "programming 1");
    Course c2("cs2", "programming 2");
    Course c3("cs3", "programming 3");

    Teacher t1("ibrahim", "ibrahim@gmail.com", "123", "cs1", 4000);
    Teacher t2("ahmed", "ahmed@gmail.com", "123", "cs2", 3000);
    Teacher t3("khaled", "khaled@gmail.com", "123", "cs3", 2000);
    teachers.insert({t1.get_id(), t1});
    teachers.insert({t2.get_id(), t2});
    teachers.insert({t3.get_id(), t3});

    Admin a(1, "admin@gmail.com", "admin", "123");
    admins.insert({1, a});

    login();
    pauseScreen();
}
