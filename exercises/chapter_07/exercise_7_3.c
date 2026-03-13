#include <stdio.h>

int ascii_to_integer(char *string) {
    int result = 0;
    
    while (*string >= '0' && *string <= '9') {
        result = result * 10 + (*string - '0');
        string++;
    }
    
    if (*string != '\0') {
        return 0;
    }
    
    return result;
}

int main(void) {
    char *test1 = "12345";
    char *test2 = "0";
    char *test3 = "12a34";
    char *test4 = "-123";
    
    printf("'%s' -> %d\n", test1, ascii_to_integer(test1));
    printf("'%s' -> %d\n", test2, ascii_to_integer(test2));
    printf("'%s' -> %d (invalid char)\n", test3, ascii_to_integer(test3));
    printf("'%s' -> %d (negative not supported)\n", test4, ascii_to_integer(test4));
    
    return 0;
}
