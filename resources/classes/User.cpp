//
// Created by hima1 on 5/16/2024.
//

#include "User.h"

User::User(int ID, string Name, string Email, string Password) {
    id = ID, name = Name, email = Email, password = Password;
}

void User::login() {

}

int User::get_id() {
    return id;
}

string User::get_name() {
    return name;
}

string User::get_email() {
    return email;
}

string User::get_password() {
    return password;
}

void User::setName(string Name) {
    name = Name;
}

void User::setEmail(string Email) {
    email = Email;
}

void User::setPassword(string Password) {
    password = Password;
}
