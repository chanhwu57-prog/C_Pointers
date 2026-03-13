#include <stdio.h>
#include <string.h>

int substr(char dst[], char src[], int start, int len) {
    int src_len = strlen(src);
    
    if (start < 0 || len < 0 || start >= src_len) {
        dst[0] = '\0';
        return 0;
    }
    
    int i;
    for (i = 0; i < len && src[start + i] != '\0'; i++) {
        dst[i] = src[start + i];
    }
    dst[i] = '\0';
    
    return i;
}

int main(void) {
    char src[] = "Hello, World!";
    char dst[100];
    
    substr(dst, src, 7, 5);
    printf("Substring from 7, length 5: %s\n", dst);
    
    substr(dst, src, 0, 5);
    printf("Substring from 0, length 5: %s\n", dst);
    
    return 0;
}
