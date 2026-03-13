#include <stdio.h>

void copy_n(char dst[], char src[], int n) {
    int src_len = 0;
    while (src[src_len] != '\0') {
        src_len++;
    }
    
    for (int i = 0; i < n; i++) {
        if (i < src_len) {
            dst[i] = src[i];
        } else {
            dst[i] = '\0';
        }
    }
}

int main(void) {
    char src[] = "Hello, World!";
    char dst[20];
    
    copy_n(dst, src, 5);
    printf("Copied 5 chars: %s\n", dst);
    
    copy_n(dst, src, 20);
    printf("Copied 20 chars: %s\n", dst);
    
    return 0;
}
