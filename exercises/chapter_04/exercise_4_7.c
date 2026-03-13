#include <stdio.h>
#include <stdbool.h>

void deblank(char string[]) {
    int i = 0;
    int j = 0;
    bool in_space = false;
    
    while (string[i] != '\0') {
        if (string[i] == ' ' || string[i] == '\t') {
            if (!in_space) {
                string[j++] = ' ';
                in_space = true;
            }
        } else {
            string[j++] = string[i];
            in_space = false;
        }
        i++;
    }
    string[j] = '\0';
}

int main(void) {
    char str1[] = "Hello    World";
    char str2[] = "  Multiple   spaces   here  ";
    
    printf("Before: '%s'\n", str1);
    deblank(str1);
    printf("After:  '%s'\n", str1);
    
    printf("\nBefore: '%s'\n", str2);
    deblank(str2);
    printf("After:  '%s'\n", str2);
    
    return 0;
}
