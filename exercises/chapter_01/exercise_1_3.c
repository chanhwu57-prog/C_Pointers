#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Reads characters from standard input, prints them, and calculates a checksum.
 *
 * This program reads characters from standard input using the getchar function.
 * For each character read, it prints the character using the putchar function.
 * It also calculates a checksum by adding each character's value to a signed char variable.
 * The checksum is initialized to -1 and is updated with each character read.
 * Finally, the program prints the checksum.
 *
 * @return int Returns 0 on successful execution.
 */ 
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
