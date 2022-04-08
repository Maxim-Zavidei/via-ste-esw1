#include <string.h>
#include "StudentHandler.h"
#include "StudentList.h"
#include "Student.h"

typedef struct studentHandler {
    studentList_t studentList;
} studentHandler_st;

studentHandler_t studentHandler_create() {
    studentHandler_t new_studenthandler = calloc(sizeof(studentHandler_st), 1);

    if (NULL == new_studenthandler) return NULL;

    new_studenthandler->studentList = createStudentList();

    return new_studenthandler;
}

void printStudentInfo(student_t student) {
    printInfo(student);
}

void printAllStudentInfo(studentHandler_t self) {
    for (int i = 0; i < noOfStudents(self->studentList); i++) {
        printInfo(getStudentByIndex(self->studentList, i));
    }
}

student_t searchStudentById(studentHandler_t self, int studentId) {

    student_t tmp_student = NULL;
    for (int i = 0; i < noOfStudents(self->studentList); i++) {
        student_t tmp_student = getStudentByIndex(self->studentList, i);
        if (student_getStudentId(tmp_student) == studentId) {
            return tmp_student;
        }
    }
    return NULL;
}

student_t searchStudentByLastName(studentHandler_t self, char* lastName) {
    student_t tmp_student = NULL;
    for (int i = 0; i < noOfStudents(self->studentList); i++) {
        student_t tmp_student = getStudentByIndex(self->studentList, i);
        if (strcmp(student_getLastName(tmp_student), lastName) == 0) {
            return tmp_student;
        }
    }
    return NULL;
}

void addStudentToHandler(studentHandler_t self, student_t student) {
    addStudent(self->studentList, student);
}
