#include <stdio.h>

float single_tax(float income) {
    static float brackets[] = {0, 23350, 56550, 117950, 256500};
    static float base_tax[] = {0, 3502.50, 12798.50, 31832.50, 81710.50};
    static float rates[] = {0.15, 0.28, 0.31, 0.36, 0.396};
    
    for (int i = 4; i >= 0; i--) {
        if (income > brackets[i]) {
            return base_tax[i] + (income - brackets[i]) * rates[i];
        }
    }
    
    return 0;
}

int main(void) {
    float incomes[] = {10000, 30000, 60000, 120000, 300000};
    int num = sizeof(incomes) / sizeof(incomes[0]);
    
    printf("Income      Tax\n");
    printf("--------  --------\n");
    for (int i = 0; i < num; i++) {
        printf("%-10.2f  %.2f\n", incomes[i], single_tax(incomes[i]));
    }
    
    return 0;
}
