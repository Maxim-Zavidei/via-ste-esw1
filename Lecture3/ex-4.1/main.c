#include <stdio.h>
#include "mystr.h"

int main(void) {

    
    char* str1 = "Hello World";
    char* str2 = "hello World";

    printf("my_strlen: %i\n", my_strlen(str1));
    printf("my_strcmp: %i\n", my_strcmp(str1, str2));
    my_strcpy(str2, str1);
    printf("my_strcpy: %s\n", str2);
    return 0;
}