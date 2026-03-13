#include <stdio.h>

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < z; j++) {
            int sum = 0;
            for (int k = 0; k < y; k++) {
                sum += *(m1 + i * y + k) * *(m2 + k * z + j);
            }
            *(r + i * z + j) = sum;
        }
    }
}

void print_matrix(int *m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", *(m + i * cols + j));
        }
        printf("\n");
    }
}

int main(void) {
    int m1[3][2] = {
        {2, -6},
        {3, 5},
        {1, -1}
    };
    
    int m2[2][4] = {
        {4, -2, -4, -5},
        {-7, -3, 6, 7}
    };
    
    int result[3][4];
    
    printf("Matrix A (3x2):\n");
    print_matrix((int *)m1, 3, 2);
    
    printf("\nMatrix B (2x4):\n");
    print_matrix((int *)m2, 2, 4);
    
    matrix_multiply((int *)m1, (int *)m2, (int *)result, 3, 2, 4);
    
    printf("\nResult A x B (3x4):\n");
    print_matrix((int *)result, 3, 4);
    
    return 0;
}
