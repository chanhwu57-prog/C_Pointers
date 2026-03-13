#include <stdio.h>
#include <string.h>

int del_substr(char *str, char const *substr) {
    if (str == NULL || substr == NULL || *substr == '\0') {
        return 0;
    }
    
    int substr_len = strlen(substr);
    char *p = str;
    
    while (*p != '\0') {
        char *s1 = p;
        const char *s2 = substr;
        
        while (*s1 == *s2 && *s2 != '\0') {
            s1++;
            s2++;
        }
        
        if (*s2 == '\0') {
            char *dest = p;
            char *src = p + substr_len;
            while (*src != '\0') {
                *dest++ = *src++;
            }
            *dest = '\0';
            return 1;
        }
        p++;
    }
    
    return 0;
}

int main(void) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    
    printf("Original: %s\n", str1);
    
    if (del_substr(str1, "World")) {
        printf("After deleting 'World': %s\n", str1);
    } else {
        printf("Substring not found\n");
    }
    
    if (del_substr(str2, "xyz")) {
        printf("After deleting 'xyz': %s\n", str2);
    } else {
        printf("Substring 'xyz' not found\n");
    }
    
    return 0;
}
