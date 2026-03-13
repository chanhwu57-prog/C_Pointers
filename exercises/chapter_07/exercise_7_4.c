#include <stdio.h>
#include <stdarg.h>

int max_list(int first, ...) {
    if (first < 0) {
        return 0;
    }
    
    int max = first;
    va_list args;
    va_start(args, first);
    
    int value;
    while ((value = va_arg(args, int)) >= 0) {
        if (value > max) {
            max = value;
        }
    }
    
    va_end(args);
    return max;
}

int main(void) {
    printf("max_list(1, 5, 3, 8, 2, -1) = %d\n", max_list(1, 5, 3, 8, 2, -1));
    printf("max_list(10, 2, 3, -1) = %d\n", max_list(10, 2, 3, -1));
    printf("max_list(5, -1) = %d\n", max_list(5, -1));
    printf("max_list(-5, 10, 20, -1) = %d\n", max_list(-5, 10, 20, -1));
    
    return 0;
}
