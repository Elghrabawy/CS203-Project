//
// Created by hima1 on 5/14/2024.
//

#include "DB.h"

Student DB::getStudent(int id) {
//    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    string name = "NULL", email = "NULL", password = "NULL";
    vector <Enrollment> enrollments;
    SQLite::Statement qryStudent(db, "SELECT * FROM students WHERE studentID = ?");
    qryStudent.bind(1, id);

    while(qryStudent.executeStep()){
        name = qryStudent.getColumn("name").getString();
        email = qryStudent.getColumn("email").getString();
        password = qryStudent.getColumn("password").getString();
    }

    SQLite::Statement qryEnrollments(db, "SELECT * FROM enrollments WHERE studentID = ?");
    qryEnrollments.bind(1, id);

    while(qryEnrollments.executeStep()){

        string courseCode = qryEnrollments.getColumn("courseCode").getString();
        int points = qryEnrollments.getColumn("grade").getInt();
        enrollments.push_back(Enrollment(id, courseCode, points));
    }


    return Student(id, name, email, password, enrollments);
}

vector<Student> DB::getAllStudents() {
    vector<Student> students;
//    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    SQLite::Statement qryStudent(db, "SELECT studentID FROM students");

    while(qryStudent.executeStep()){
        int studentID = qryStudent.getColumn("studentID").getInt();
        students.push_back(getStudent(studentID));
    }

    return students;
}

bool DB::modifyStudentInfo(int id, string value, DB::fields field) {
//    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    SQLite::Statement qryStudent(db, "SELECT COUNT(*) as count FROM students WHERE studentID = ?" );
    qryStudent.bind(1, id);
    qryStudent.executeStep();

    if(qryStudent.getColumn("count").getInt() > 0){
        switch (field) {
            case _NAME: {
                SQLite::Statement qryModify(db, "UPDATE students SET name = ? WHERE studentID = ?");
                qryModify.bind(1, value);
                qryModify.bind(2, id);
                qryModify.exec();
                qryModify.reset();
                break;
            }
            case _EMAIL:{
                SQLite::Statement qryModify(db, "UPDATE students SET email = ? WHERE studentID = ?");
                qryModify.bind(1, value);
                qryModify.bind(2, id);
                qryModify.exec();
                qryModify.reset();
                break;
            }

            case _PASSWORD:{
                SQLite::Statement qryModify(db, "UPDATE students SET password = ? WHERE studentID = ?");
                qryModify.bind(1, value);
                qryModify.bind(2, id);
                qryModify.exec();
                qryModify.reset();
                break;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

int DB::addNewStudent(string name, string email, string password) {
//    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    SQLite::Statement qryInsertStudent(
            db,
            "INSERT INTO students(name, email, password) VALUES(?, ?, ?) returning studentID"
    );
    qryInsertStudent.bind(1, name);
    qryInsertStudent.bind(2, email);
    qryInsertStudent.bind(3, password);

    qryInsertStudent.executeStep();
    return qryInsertStudent.getColumn("studentID");
}

int DB::addNewEnrollment(string code, int studentID) {
    Course course = getCourse(code);
    if(!course.is()){
        return -1;
    }

    Student student = getStudent(studentID);
    if(!student.is()){
        return -1;
    }

    SQLite::Statement qryNewEnrollment(
            db,
            "INSERT INTO enrollments(courseCode, studentID, grade) VALUES(?, ?, -1) returning enrollmentID"
    );
    qryNewEnrollment.bind(1, code);
    qryNewEnrollment.bind(2, studentID);

    qryNewEnrollment.executeStep();
    return qryNewEnrollment.getColumn("enrollmentID");
}

Teacher DB::getTeacher(int id) {
//    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    string name = "NULL", email = "NULL", password = "NULL", courseCode = "NULL";
    double salary = -1;

    SQLite::Statement qryTeacher(db, "SELECT * FROM teachers WHERE teacherID = ?");
    qryTeacher.bind(1, id);

    if(qryTeacher.executeStep()){
        name = qryTeacher.getColumn("name").getString();
        email = qryTeacher.getColumn("email").getString();
        password = qryTeacher.getColumn("password").getString();
        courseCode = qryTeacher.getColumn("courseCode").getString();
        salary = qryTeacher.getColumn("salary").getDouble();
    }

    return Teacher(id, name, email, password, courseCode, salary);
}

vector<Teacher> DB::getAllTeachers() {
    vector<Teacher> teachers;
//    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    SQLite::Statement qryTeachers(db, "SELECT teacherID FROM teachers");

    while(qryTeachers.executeStep()){
        int teacherID = qryTeachers.getColumn("teacherID").getInt();
        teachers.push_back(getTeacher(teacherID));
    }
    return teachers;
}

bool DB::modifyTeacher(int id, string value, DB::fields field) {
    try {
//        SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        SQLite::Statement qryTeacher(db, "SELECT COUNT(*) as count FROM teachers WHERE teacherID = ?");
        qryTeacher.bind(1, id);
        qryTeacher.executeStep();
        if(qryTeacher.getColumn("count").getInt() > 0) {


            switch (field) {
                case _NAME: {
                    SQLite::Statement qryModify(db, "UPDATE teachers SET name = ? WHERE teacherID = ?");
                    qryModify.bind(1, value);
                    qryModify.bind(2, id);
                    qryModify.exec();
                    qryModify.reset();
                    return true;
                    break;
                }
                case _EMAIL: {
                    SQLite::Statement qryModify(db, "UPDATE teachers SET email = ? WHERE teacherID = ?");
                    qryModify.bind(1, value);
                    qryModify.bind(2, id);
                    qryModify.exec();
                    qryModify.reset();
                    return true;
                    break;
                }
                case _PASSWORD: {
                    SQLite::Statement qryModify(db, "UPDATE teachers SET password = ? WHERE teacherID = ?");
                    qryModify.bind(1, value);
                    qryModify.bind(2, id);
                    qryModify.exec();
                    qryModify.reset();
                    return true;
                    break;
                }
                case _CODE: {
                    SQLite::Statement qryModify(db, "UPDATE teachers SET courseCode = ? WHERE teacherID = ?");
                    qryModify.bind(1, value);
                    qryModify.bind(2, id);
                    qryModify.exec();
                    qryModify.reset();
                    return true;
                    break;
                }
                default :
                    return false;
            }
        }
        else{
            return false;
        }
    }
    catch (exception &e){
        cout << e.what() << endl;
        return false;
    }
}
bool DB::modifyTeacher(int id, float value, DB::fields field) {
    try {
//        SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        SQLite::Statement qryTeacher(db, "SELECT COUNT(*) as count FROM teachers WHERE teacherID = ?");
        qryTeacher.bind(1, id);
        qryTeacher.executeStep();
        if(qryTeacher.getColumn("count").getInt() > 0) {
            switch (field) {
                case _SALARY: {
                    SQLite::Statement qryModify(db, "UPDATE teachers SET salary = ? WHERE teacherID = ?");
                    qryModify.bind(1, value);
                    qryModify.bind(2, id);
                    qryModify.exec();
                    qryModify.reset();
                    return true;
                    break;
                }
                default :
                    return false;
            }
        }
        else{
            return false;
        }
    }
    catch (exception &e){
        cout << e.what() << endl;
        return false;
    }
}

int DB::addNewTeacher(string name, string email, string password, string courseCode, float salary) {
//    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    SQLite::Statement qryInsertTeacher(
            db,
            "INSERT INTO teachers(name, email, password, courseCode, salary) VALUES(?, ?, ?, ?, ?) returning teacherID"
    );
    qryInsertTeacher.bind(1, name);
    qryInsertTeacher.bind(2, email);
    qryInsertTeacher.bind(3, password);
    qryInsertTeacher.bind(4, courseCode);
    qryInsertTeacher.bind(5, salary);

    qryInsertTeacher.executeStep();
    return qryInsertTeacher.getColumn("teacherID");
}

Course DB::getCourse(string code) {
//    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    vector <int> studentIDs;
    string courseTitle = "NULL";

    SQLite::Statement qryCourse(db, "SELECT * FROM courses WHERE courseCode = ?");
    qryCourse.bind(1, code);

    while(qryCourse.executeStep()){
        courseTitle = qryCourse.getColumn("title").getString();
    }

    SQLite::Statement qryEnrollments(db, "SELECT studentID FROM enrollments WHERE courseCode = ?");
    qryEnrollments.bind(1, code);

    while(qryEnrollments.executeStep()){
        int studentID = qryEnrollments.getColumn("studentID").getInt();
        studentIDs.push_back(studentID);
    }

    return Course(code, courseTitle, studentIDs);
}

vector<Course> DB::getAllCourses() {
    vector<Course> courses;
//    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    SQLite::Statement qryCourses(db, "SELECT * FROM courses");

    while (qryCourses.executeStep()){
        courses.push_back(getCourse(qryCourses.getColumn("courseCode")));
    }
    return courses;
}

bool DB::modifyEnrollment(int studentID, string courseCode, int points) {
    SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    SQLite::Statement qryEnrollment(db, "SELECT COUNT(*) as count FROM enrollments WHERE courseCode = ? AND studentID = ?");
    qryEnrollment.bind(1, courseCode);
    qryEnrollment.bind(2, studentID);
    qryEnrollment.executeStep();

    if(qryEnrollment.getColumn("count").getInt() == 0){
        return false;
    }

    SQLite::Statement qryModify(db, "UPDATE enrollments SET grade = ? WHERE studentID = ? AND courseCode = ?");
    qryModify.bind(1, points);
    qryModify.bind(2, studentID);
    qryModify.bind(3, courseCode);

    qryModify.executeStep();
    return true;
}

vector<string> DB::getNotEnrolledCourses(int studentID) {
    vector<string> coursesCodes;
    string stmEnrolledCourses = "SELECT courseCode FROM enrollments WHERE studentID = ?";
    string stmNotEnrolledCourses = "SELECT courseCode FROM courses WHERE courseCode NOT IN (" + stmEnrolledCourses + ")";

    SQLite::Statement qryCourse(db, stmNotEnrolledCourses);
    qryCourse.bind(1, studentID);

    while(qryCourse.executeStep()){
        coursesCodes.push_back(qryCourse.getColumn("courseCode").getString());
    }
    return coursesCodes;
}

vector<pair<Student, Enrollment>> DB::getStudentsOfTeacher(int teacherID) {
    vector<pair<Student, Enrollment>> students;
    string stm = R"(
        SELECT students.name AS studentName, students.studentID AS studentID, students.email AS studentEmail, students.password AS studentPassword,
        enrollments.courseCode AS courseCode, enrollments.grade AS grade
            FROM students JOIN enrollments JOIN courses JOIN teachers
                WHERE
                students.studentID = enrollments.studentID
                AND enrollments.courseCode = courses.courseCode
                AND courses.courseCode = teachers.courseCode
                AND teachers.teacherID = ?;
    )";
    SQLite::Statement qryStudents(db, stm);
    qryStudents.bind(1, teacherID);

    while(qryStudents.executeStep()){
        string studentName = qryStudents.getColumn("studentName").getString();
        int studentID = qryStudents.getColumn("studentID").getInt();
        string studentEmail = qryStudents.getColumn("studentEmail").getString();
        string studentPassword = qryStudents.getColumn("studentPassword").getString();
        string courseCode = qryStudents.getColumn("courseCode").getString();
        int grade = qryStudents.getColumn("grade").getInt();

        Student student(studentID, studentName, studentEmail, studentPassword, {});
        Enrollment enrollment(studentID, courseCode, grade);

        students.push_back(make_pair(student, enrollment));
    }
    return students;
}



