#include <stdio.h>

int main(void) {
    double a, b, c;
    
    printf("Enter three sides of a triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Invalid triangle: sides must be positive\n");
        return 1;
    }
    
    if (a + b <= c || b + c <= a || a + c <= b) {
        printf("Invalid triangle: sum of any two sides must be greater than the third\n");
        return 1;
    }
    
    if (a == b && b == c) {
        printf("Equilateral triangle\n");
    } else if (a == b || b == c || a == c) {
        printf("Isosceles triangle\n");
    } else {
        printf("Scalene triangle\n");
    }
    
    return 0;
}
