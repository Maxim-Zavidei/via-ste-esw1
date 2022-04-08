#include "person.h"
#include <stdlib.h>

typedef struct person{
    int cpr;
    char* name;
    cat_t cat;
} person;


person_t create_person(int cpr, char* name){
    person_t new_person = calloc(sizeof(person), 1);
    if (NULL == new_person) return NULL;

    new_person -> cpr = cpr;
    new_person -> name = name;
    new_person -> cat = NULL;

    return new_person;
}


void person_destroy(person_t self){
    if(self == NULL) return;
    free(self);
}

void adoptCat(person_t self, cat_t cat) {
    if(self == NULL) return;
    self->cat = cat;
}

void feedCat(person_t self, char* foodType) {
    if(self == NULL) return;
    feed(self->cat, foodType);
}

void petCat(person_t self) {
    if(self == NULL) return;
    pet(self->cat);
}

void playWithCat(person_t self) {
    if(self == NULL) return;
    play(self->cat);
}
