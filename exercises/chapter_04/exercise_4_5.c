#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int main(void) {
    char current[MAX_LINE];
    char previous[MAX_LINE] = "";
    
    while (fgets(current, MAX_LINE, stdin) != NULL) {
        if (strcmp(current, previous) == 0) {
            printf("%s", current);
        }
        strcpy(previous, current);
    }
    
    return 0;
}
