# Software Requirements Specification

## Table of Contents
- [Introduction](#introduction)
  - [Purpose](#purpose)
  - [Scope](#scope)
  - [Definitions, Acronyms, and Abbreviations](#definitions-acronyms-and-abbreviations)
  - [References](#references)
- [Functional Requirements](#functional-requirements)
  - [Student](#student)
  - [Teacher](#teacher)
  - [Administrator](#administrator)
  - [Course](#course)

## Introduction
### Purpose
> The purpose of this document is to provide a detailed description of the requirements for the Educational Management System. It will explain the purpose and features of the system, the interfaces of the system, what the system will do, the constraints under which it must operate and how the system will react to external stimuli.

### Scope
> The EMS is a web-based application providing functionalities for students, teachers, and administrator. Kye features include student enrollment, course management, faculty details, grade management, and reporting.

### Definitions Acronyms and Abbreviations
> - EMS: Educational Management System
> - SRS: Software Requirements Specification
> - UML: Unified Modeling Language
> - DFD: Data Flow Diagram
> - ERD: Entity Relationship Diagram
> - SQL: Structured Query Language
> - GUI: Graphical User Interface

### References
> - [SQLite Library](https://github.com/SRombauts/SQLiteCpp)


## Functional Requirements
### Student
> - Students can enroll in courses, view/delete enrolled courses, calculate GPA, view/modify personal info, view schedule, and log in.

### Teacher
> - Teachers can view courses, manage grades, view student info, modify info, and login.

### Administrator
> - Admins can login, add, remove and modify students and teachers and courses.

### Course
> - The system can manage course details, enroll, remove students and print course details.