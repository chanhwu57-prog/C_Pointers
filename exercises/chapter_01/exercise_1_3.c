#include <stdio.h>

int main(void) {
    int ch;
    signed char checksum = -1;

    while ((ch = getchar()) != EOF) {
        putchar(ch);
        checksum += (signed char)ch;
    }

    printf("%d\n", checksum);
    return 0;
}
