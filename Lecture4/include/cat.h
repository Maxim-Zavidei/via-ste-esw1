#pragma once 

typedef struct cat* cat_t;

cat_t create_cat(int id, char* name, char* eyeColor, char* furColor);
void cat_destroy(cat_t self);
void feed(cat_t self, char* foodType);
void pet(cat_t self);
void play(cat_t self);