#include <stdio.h>
#include <string.h>

void reverse_string(char *string) {
    if (string == NULL) return;
    
    char *start = string;
    char *end = string + strlen(string) - 1;
    
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void) {
    char str1[] = "Hello, World!";
    char str2[] = "abcdef";
    char str3[] = "a";
    
    printf("Original: %s\n", str1);
    reverse_string(str1);
    printf("Reversed: %s\n", str1);
    
    printf("\nOriginal: %s\n", str2);
    reverse_string(str2);
    printf("Reversed: %s\n", str2);
    
    printf("\nOriginal: %s\n", str3);
    reverse_string(str3);
    printf("Reversed: %s\n", str3);
    
    return 0;
}
