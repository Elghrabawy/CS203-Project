//
// Created by hima1 on 5/16/2024.
//

#include "Enrollment.h"

Enrollment::Enrollment(string Code, int Points) {
    if(Points != -1){
        if(Points > 100 || Points < 0){
            cout << "Pointes must be greater than or equal 0 and less than or equal 100" << endl;
            exit(-1);
        }
    }

    courseCode = Code, points = Points;
}
Enrollment::Enrollment(int StudentID, string Code, int Points) {
    if(Points != -1){
        if(Points > 100 || Points < 0){
            cout << "Pointes must be greater than or equal 0 and less than or equal 100" << endl;
            exit(-1);
        }
    }

    courseCode = Code, points = Points, studentID = StudentID;
}


string Enrollment::get_code() {
    return courseCode;
}

int Enrollment::get_points() {
    return points;
}

string Enrollment::get_grade() {
    if(points >= 95){
        return "A+";
    }else if(points >= 90){
        return "A";
    }else if(points >= 85){
        return "A-";
    }else if(points >= 80){
        return "B+";
    }else if(points >= 75){
        return "B";
    }else if(points >= 70){
        return "C+";
    }else if(points >= 65){
        return "C";
    }else if(points >= 60){
        return "D+";
    }else if(points >= 55){
        return "D";
    }else if(points >= 50){
        return "D-";
    }else{
        if(points == -1){
            return "NAN";
        }
        else{
            return "F";
        }
    }
}

void Enrollment::set_points(int Points) {
    if(points > 100 || points < 0){
        cout << "Pointes must be greater than or equal 0 and less than or equal 100" << endl;
        exit(-1);
    }
    points = Points;
}

