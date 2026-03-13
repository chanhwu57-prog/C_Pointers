#include <stdio.h>
#include <stdbool.h>

bool identity_matrix(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value = *(matrix + i * size + j);
            if (i == j) {
                if (value != 1) {
                    return false;
                }
            } else {
                if (value != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main(void) {
    int matrix3x3[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    
    int matrix4x4[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 2}
    };
    
    int matrix5x5[5][5] = {
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1}
    };
    
    printf("3x3 identity matrix: %s\n", 
           identity_matrix((int *)matrix3x3, 3) ? "true" : "false");
    printf("4x4 not identity matrix: %s\n", 
           identity_matrix((int *)matrix4x4, 4) ? "true" : "false");
    printf("5x5 identity matrix: %s\n", 
           identity_matrix((int *)matrix5x5, 5) ? "true" : "false");
    
    return 0;
}
