#include <stdio.h>

char *find_char(char const *source, char const *chars) {
    if (source == NULL || chars == NULL) {
        return NULL;
    }
    
    const char *p = chars;
    while (*p != '\0') {
        const char *s = source;
        while (*s != '\0') {
            if (*s == *p) {
                return (char *)s;
            }
            s++;
        }
        p++;
    }
    
    return NULL;
}

int main(void) {
    char source[] = "Hello, World!";
    char chars1[] = "xyz";
    char chars2[] = "oW";
    
    char *result;
    
    result = find_char(source, chars1);
    if (result) {
        printf("Found '%c' at position %ld\n", *result, result - source);
    } else {
        printf("No characters from \"%s\" found\n", chars1);
    }
    
    result = find_char(source, chars2);
    if (result) {
        printf("Found '%c' at position %ld\n", *result, result - source);
    } else {
        printf("No characters from \"%s\" found\n", chars2);
    }
    
    return 0;
}
