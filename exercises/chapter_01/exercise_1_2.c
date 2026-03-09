#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Reads lines from standard input and prints them with line numbers.
 *
 * This program reads lines from standard input using the getline function.
 * For each line read, it prints the line number followed by the line content.
 * The line numbers start from 1 and are incremented for each line read.
 *
 * @return int Returns 0 on successful execution.
 */
int main(){
    char* input = NULL;
    size_t bufsize = 0;
    int line_number = 1;
    while(getline(&input, &bufsize, stdin) != -1){
        printf("%d %s", line_number, input);
        line_number++;
    }
    free(input);
    return 0;
}
/*
int main(void) {
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t chars_read;
    int line_number = 1;

    while ((chars_read = getline(&line, &bufsize, stdin)) != -1) {
        printf("%d %s", line_number, line);
        line_number++;
    }

    free(line);
    return 0;
}
*/