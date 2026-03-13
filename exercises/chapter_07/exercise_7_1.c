#include <stdio.h>

int hermite(int n, int x) {
    if (n <= 0) {
        return 1;
    }
    if (n == 1) {
        return 2 * x;
    }
    return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}

int main(void) {
    printf("Hermite polynomial H_n(x):\n");
    printf("H_0(3) = %d\n", hermite(0, 3));
    printf("H_1(3) = %d\n", hermite(1, 3));
    printf("H_2(3) = %d\n", hermite(2, 3));
    printf("H_3(3) = %d\n", hermite(3, 3));
    printf("H_4(3) = %d\n", hermite(4, 3));
    
    return 0;
}
