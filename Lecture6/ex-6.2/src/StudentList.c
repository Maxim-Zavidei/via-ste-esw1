#include <stdlib.h>
#include "StudentList.h"

typedef struct studentList {
    LinkedList_t adaptee;
} studentList_st;

studentList_t createStudentList() {
    studentList_t new_studentlist = calloc(sizeof(studentList_st), 1);

    if (NULL == new_studentlist) return NULL;

    new_studentlist->adaptee = create();

    return new_studentlist;
}

enum LinkedListReturnCode addStudent(studentList_t self, student_t student) {
    return push(self->adaptee, student);
}

enum LinkedListReturnCode getStudent(studentList_t self, student_t student) {
    return containsItem(self->adaptee, student);
}

enum LinkedListReturnCode removeStudent(studentList_t self, student_t student) {
    return removeItem(self->adaptee, student);
}

student_t getStudentByIndex(studentList_t self, int index) {
    return peekItemByIndex(self->adaptee, index);
}

uint16_t noOfStudents(studentList_t self) {
    return length(self->adaptee);
}
