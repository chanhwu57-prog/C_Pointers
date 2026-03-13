#include <stdio.h>

unsigned int store_bit_field(int original_value, int value_to_store,
                            unsigned int starting_bit, unsigned int ending_bit) {
    unsigned int mask = 0;
    
    for (unsigned int i = ending_bit; i <= starting_bit; i++) {
        mask |= (1u << i);
    }
    
    original_value &= ~mask;
    
    value_to_store <<= ending_bit;
    value_to_store &= mask;
    
    return original_value | value_to_store;
}

void print_binary(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");
    }
    printf("\n");
}

int main(void) {
    unsigned int original = 0xFFFF;
    int value = 0x123;
    
    printf("Original: ");
    print_binary(original);
    printf("Value to store: ");
    print_binary(value);
    
    unsigned int result = store_bit_field(original, value, 15, 4);
    printf("After storing (bits 15-4): ");
    print_binary(result);
    printf("Result: 0x%08X\n", result);
    
    return 0;
}
