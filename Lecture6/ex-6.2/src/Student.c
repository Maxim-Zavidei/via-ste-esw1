#include <stdlib.h>
#include <stdio.h>
#include "Student.h"

typedef struct student {
    char* firstName;
    char* lastName;
    int studentId;
    char* nationality;
} student_st;

student_t student_create(char* firstName, char* lastName, int studentId, char* nationality) {
    student_t new_student = calloc(sizeof(student_st), 1);

    if (NULL == new_student) return NULL;

    strncpy(new_student->firstName, firstName, sizeof(new_student->firstName) - 1);
    strncpy(new_student->lastName, lastName, sizeof(new_student->lastName) - 1);
    new_student->studentId = studentId;
    strncpy(new_student->nationality, nationality, sizeof(new_student->nationality) - 1);

    return new_student;
}

void student_destroy(student_t self) {
    if (NULL == self) return;
    free(self);
}

char* student_getFirstName(student_t self) {
    if (NULL == self) return NULL;
    return self->firstName;
}

char* student_getLastName(student_t self) {
    if (NULL == self) return NULL;
    return self->lastName;
}

int student_getStudentId(student_t self) {
    if (NULL == self) return -1;
    return self->studentId;
}

char* student_getNationality(student_t self) {
    if (NULL == self) return NULL;
    return self->nationality;
}

void student_setFirstName(student_t self, char* firstName) {
    if (NULL == self) return;
    strncpy(self->firstName, firstName, sizeof(self->firstName) - 1);
}

void student_setLastName(student_t self, char* lastName) {
    if (NULL == self) return;
    strncpy(self->lastName, lastName, sizeof(self->lastName) - 1);
}

void student_setStudentId(student_t self, int studentId) {
    if (NULL == self) return;
    self->studentId = studentId;
}

void student_setNationality(student_t self, char* nationality) {
    if (NULL == self) return;
    strncpy(self->nationality, nationality, sizeof(self->nationality) - 1);
}

void student_printInfo(student_t self) {
    printf("Student: {firstName: %s, lastName: %s, studentId: %i, nationality: %s}\n", self->firstName, self->lastName, self->studentId, self->nationality);
}
