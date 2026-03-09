#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
