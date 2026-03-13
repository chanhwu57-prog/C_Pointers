#include <stdio.h>

int gcd(int m, int n) {
    if (m < 0) m = -m;
    if (n < 0) n = -n;
    
    if (n == 0) {
        return m;
    }
    return gcd(n, m % n);
}

int gcd_iterative(int m, int n) {
    if (m < 0) m = -m;
    if (n < 0) n = -n;
    
    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main(void) {
    printf("GCD (Greatest Common Divisor):\n");
    printf("gcd(48, 18) = %d\n", gcd(48, 18));
    printf("gcd(56, 42) = %d\n", gcd(56, 42));
    printf("gcd(100, 35) = %d\n", gcd(100, 35));
    printf("gcd(17, 13) = %d\n", gcd(17, 13));
    
    printf("\nUsing iterative version:\n");
    printf("gcd(48, 18) = %d\n", gcd_iterative(48, 18));
    
    return 0;
}
