#include <stdlib.h>
#include "cat.h"

typedef struct cat {
    int id;
    char* name;
    char* eyeColor;
    char* furColor;
} cat;

cat_t create_cat(int id, char* name, char* eyeColor, char* furColor) {
    cat_t new_cat = calloc(sizeof(cat), 1);
    if (NULL == new_cat) reutrn NULL;

    new_cat -> id = id;
    strncpy(new_cat->name, name, sizeof(new_cat->name) - 1);
    strncpy(new_cat->eyeColor, eyeColor, sizeof(new_cat->eyeColor) - 1);
    strncpy(new_cat->furColor, furColor, sizeof(new_cat->furColor) - 1);

    return new_cat;
}

void cat_destroy(cat_t self) {
    if(self == NULL) return;
    free(self);
}

void feed(cat_t self, char* foodType) {
    if(self == NULL) return;
    printf("The cat %s is now eating %s.", self->name, foodType);
}

void pet(cat_t self) {
    if(self == NULL) return;
    printf("The cat %s is now petted.", self->name);
}

void play(cat_t self) {
    if(self == NULL) return;
    printf("The cat %s is now playing.", self->name);
}