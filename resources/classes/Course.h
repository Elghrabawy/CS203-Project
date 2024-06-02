//
// Created by hima1 on 5/16/2024.
//

#ifndef OOP_PROJECT_COURSE_H
#define OOP_PROJECT_COURSE_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Course {
private:
    vector <int> studentsIDs;
    string courseCode;
    string courseTitle;
public:
    Course(string CODE, string TITLE);
    Course(string CODE, string TITLE, vector<int> STUDENTSIDS);
    string get_code();
    string get_title();
    vector <int> getStudentIDs();
    void add_student(int id);
    void rem_student(int id);
    bool is();
};


#endif //OOP_PROJECT_COURSE_H