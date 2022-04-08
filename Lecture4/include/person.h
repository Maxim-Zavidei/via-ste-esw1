#pragma once 
#include "cat.h"

typedef struct person* person_t;

person_t create_person(int cpr, char* name);
void person_destroy(person_t self);
void adoptCat(person_t self, cat_t cat);
void feedCat(person_t self, char* foodType);
void petCat(person_t self);
void playWithCat(person_t self);
