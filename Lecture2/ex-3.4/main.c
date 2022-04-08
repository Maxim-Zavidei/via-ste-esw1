#include<stdio.h>
#include "my_string_func.h"

#define MAX_LENGTH 1000

int main() {
    char line[MAX_LENGTH];
    char upper[MAX_LENGTH];
    int line_length;

    while (line_length = read_line(line)) {
        my_to_upper(line, upper);
        printf("Length: %d\t%s\n", line_length, upper);
    }
    return 0;
}