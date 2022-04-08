#include <stdio.h>
#include "my_string_func.h"

/* read_line: read a line into s, return length */
int read_line(char s[])
{
    int c = 0;
    int i = 0;
    int done = 0;
    do {
        c = getchar();
        if (c == EOF|| c == '\n') {
            done = 1;
        } else {
            s[i++] = c;
        }
    } while(!done);
    s[i] = '\0';
    return i;
}

void my_to_upper(char*str_in, char*str_out) {
    for (int i = 0; str_in[i] != '\0'; i++)
    {
        *(str_out++) = str_in[i] - ('a' <= str_in[i] && str_in[i] <= 'z' ? 32 : 0);
    }
    *str_out = '\0';
}