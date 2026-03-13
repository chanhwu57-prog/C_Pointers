#include <stdio.h>
#include <stdarg.h>

int array_offset(int arrayinfo[], ...) {
    int dims = arrayinfo[0];
    
    if (dims < 1 || dims > 10) {
        return -1;
    }
    
    int indices[10];
    va_list args;
    va_start(args, arrayinfo);
    
    for (int i = 0; i < dims; i++) {
        indices[i] = va_arg(args, int);
    }
    va_end(args);
    
    for (int i = 0; i < dims; i++) {
        int lo = arrayinfo[1 + 2 * i];
        int hi = arrayinfo[2 + 2 * i];
        
        if (lo > hi) {
            return -1;
        }
        if (indices[i] < lo || indices[i] > hi) {
            return -1;
        }
    }
    
    int loc = indices[0] - arrayinfo[1];
    
    for (int i = 1; i < dims; i++) {
        int hi = arrayinfo[2 * i];
        int lo = arrayinfo[1 + 2 * i];
        loc = loc * (hi - lo + 1) + indices[i] - lo;
    }
    
    return loc;
}

int main(void) {
    int arrayinfo[] = {3, 4, 6, 1, 5, -3, 3};
    
    printf("Test array_offset with arrayinfo = {3, 4, 6, 1, 5, -3, 3}\n");
    printf("(3 dimensions: dim1=[4,6], dim2=[1,5], dim3=[-3,3])\n\n");
    
    printf("offset(4, 1, -3) = %d (expected: 0)\n", array_offset(arrayinfo, 4, 1, -3));
    printf("offset(4, 1, 3) = %d (expected: 6)\n", array_offset(arrayinfo, 4, 1, 3));
    printf("offset(5, 1, -3) = %d (expected: 35)\n", array_offset(arrayinfo, 5, 1, -3));
    printf("offset(4, 1, -2) = %d (expected: 1)\n", array_offset(arrayinfo, 4, 1, -2));
    printf("offset(4, 2, -3) = %d (expected: 7)\n", array_offset(arrayinfo, 4, 2, -3));
    printf("offset(6, 3, 1) = %d (expected: 88)\n", array_offset(arrayinfo, 6, 3, 1));
    
    return 0;
}
