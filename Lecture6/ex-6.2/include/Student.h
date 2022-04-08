#pragma once

typedef struct student* student_t;

student_t student_create(char* firstName, char* lastName, int studentId, char* nationality);
void student_destroy(student_t self);

char* student_getFirstName(student_t self);
char* student_getLastName(student_t self);
int student_getStudentId(student_t self);
char* student_getNationality(student_t self);

void student_setFirstName(student_t self, char* firstName);
void student_setLastName(student_t self, char* lastName);
void student_setStudentId(student_t self, int studentId);
void student_setNationality(student_t self, char* nationality);

void student_printInfo(student_t self);
