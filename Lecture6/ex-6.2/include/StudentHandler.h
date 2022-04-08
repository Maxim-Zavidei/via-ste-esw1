#pragma once
#include "Student.h"

typedef struct studentHandler* studentHandler_t;

studentHandler_t studentHandler_create();
void printStudentInfo(student_t student);
void printAllStudentInfo(studentHandler_t self);
student_t searchStudentById(studentHandler_t self, int studentId);
student_t searchStudentByLastName(studentHandler_t self, char* lastName);
void addStudentToHandler(studentHandler_t self, student_t student);
