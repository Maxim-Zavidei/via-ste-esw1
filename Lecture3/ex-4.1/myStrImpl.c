int my_strlen(const char* str) {
    int length = 0;
    while (str[length++] != '\0');
    return length;
}

int my_strcmp(const char* str1, const char* str2) {
    if (my_strlen(str1) != my_strlen(str2)) return -1;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] != str2[i]) return -1;
    }
    return 0;
}

char* my_strcpy(char* dest, const char* src) {
    char *saved = dest;
    while (*src)
    {
        *dest++ = *src++;
     }
    *dest = 0;
    return saved;
}

char* my_strdup(const char* str) {
    char* c = malloc(sizeof(char) * my_strlen(str));
    my_strcpy(c, str);
    return c;
}