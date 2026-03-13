#include <stdio.h>

int main(void) {
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            if (c >= 'A' && c <= 'M') {
                c = c + 13;
            } else {
                c = c - 13;
            }
        } else if (c >= 'a' && c <= 'z') {
            if (c >= 'a' && c <= 'm') {
                c = c + 13;
            } else {
                c = c - 13;
            }
        }
        putchar(c);
    }
    
    return 0;
}
