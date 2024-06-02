cmake_minimum_required(VERSION 3.23)
project(oop_project)

set(CMAKE_CXX_STANDARD 20)

include_directories(resources)
include_directories(${CMAKE_SOURCE_DIR}/)

set(SQLITECPP_RUN_CPPCHECK OFF CACHE BOOL "" FORCE)
set(SQLITECPP_RUN_CPPLINT OFF CACHE BOOL "" FORCE)

add_executable(oop_project main.cpp resources/classes/Course.cpp resources/classes/Course.h resources/classes/User.cpp resources/classes/User.h resources/classes/Student.cpp resources/classes/Student.h resources/classes/Enrollment.cpp resources/classes/Enrollment.h resources/classes/Teacher.cpp resources/classes/Teacher.h resources/classes/Admin.cpp resources/classes/Admin.h resources/classes/Global.cpp resources/classes/Global.h
        resources/classes/DB.cpp
        config.h)

add_subdirectory(SQLiteCpp)

target_link_libraries(oop_project SQLiteCpp)