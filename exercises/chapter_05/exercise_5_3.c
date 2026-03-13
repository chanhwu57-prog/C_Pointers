#include <stdio.h>

unsigned int reverse_bits(unsigned int value) {
    unsigned int result = 0;
    int bits = sizeof(unsigned int) * 8;
    
    for (int i = 0; i < bits; i++) {
        result <<= 1;
        result |= (value & 1);
        value >>= 1;
    }
    
    return result;
}

void print_binary(unsigned int n) {
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

int main(void) {
    unsigned int value = 25;
    
    printf("Original value: %u\n", value);
    printf("Binary:         ");
    print_binary(value);
    
    unsigned int reversed = reverse_bits(value);
    printf("Reversed:       %u\n", reversed);
    printf("Binary:         ");
    print_binary(reversed);
    
    return 0;
}
