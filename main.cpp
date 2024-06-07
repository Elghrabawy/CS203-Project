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

    Teacher teacher = DB::getTeacher(id);
    if(!teacher.is()) {
        return -1;
    }
    else {
        string password;
        cout << printAlign("Teacher Password", CENTER, 78) << endl;
        cout << string(78 / 2 - 5, ' ') << " : ";
        cin >> password;

        if (teacher.get_password() == password)
            return id;
        else
            return -2;
    }
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
                Teacher cur = DB::getTeacher(id);
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
                cur.login();
            }
            break;
        }
    }
}

int main() {
    cout << "\033[1;31m";
    display_logo();
    displayName();

    Admin a(1, "admin@gmail.com", "admin", "123");
    admins.insert({1, a});

    login();
    pauseScreen();
}
