#include <stdio.h>
#include <math.h>

int main(void) {
    double value;
    
    printf("Enter a number: ");
    scanf("%lf", &value);
    
    if (value < 0) {
        printf("Cannot calculate square root of negative number\n");
        return 1;
    }
    
    printf("Square root of %.2f is %.6f\n", value, sqrt(value));
    
    return 0;
}
