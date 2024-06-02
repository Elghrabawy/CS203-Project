//
// Created by hima1 on 5/16/2024.
//

#ifndef OOP_PROJECT_USER_H
#define OOP_PROJECT_USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
protected:
    int id;
    string name;
    string email;
    string password;

public:
    User(int id, string NAME, string EMAIL, string PASSWORD);
    int get_id();
    string get_name();
    string get_email();
    string get_password();
    void setName(string Name);
    void setEmail(string Email);
    void setPassword(string Password);
    virtual void login();
};


#endif //OOP_PROJECT_USER_H
