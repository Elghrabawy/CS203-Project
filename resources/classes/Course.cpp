//
// Created by hima1 on 5/16/2024.
//

#include "Course.h"

Course::Course(string Code, string Title) {
    courseCode = Code, courseTitle = Title;
}

Course::Course(string Code, string Title, vector<int> StudentIDs) {
    courseCode = Code, courseTitle = Title, studentsIDs = StudentIDs;
}

string Course::get_code() {
    return courseCode;
}

string Course::get_title() {
    return courseTitle;
}

void Course::add_student(int id) {
    studentsIDs.push_back(id);
}

void Course::rem_student(int id) {
    studentsIDs.erase(find(studentsIDs.begin(), studentsIDs.end(), id));
}

vector<int> Course::getStudentIDs() {
    return studentsIDs;
}

bool Course::is() {
    return (courseTitle != "NULL");
}

