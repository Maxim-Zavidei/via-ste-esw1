#pragma once
#include "Student.h"
#include "LinkedList.h"

typedef struct studentList* studentList_t;

studentList_t createStudentList();
enum LinkedListReturnCode addStudent(studentList_t self, student_t student);
enum LinkedListReturnCode getStudent(studentList_t self, student_t student);
enum LinkedListReturnCode removeStudent(studentList_t self, student_t student);
student_t getStudentByIndex(studentList_t self, int index);
uint16_t noOfStudents(studentList_t self);
