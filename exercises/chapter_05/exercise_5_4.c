#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BITS_PER_CHAR CHAR_BIT

typedef struct {
    unsigned char *bits;
    int size;
} BitArray;

BitArray *bit_array_create(int size) {
    BitArray *ba = malloc(sizeof(BitArray));
    int bytes = (size + BITS_PER_CHAR - 1) / BITS_PER_CHAR;
    ba->bits = calloc(bytes, 1);
    ba->size = size;
    return ba;
}

void bit_array_destroy(BitArray *ba) {
    if (ba) {
        free(ba->bits);
        free(ba);
    }
}

void set_bit(BitArray *ba, int index) {
    if (index >= 0 && index < ba->size) {
        ba->bits[index / BITS_PER_CHAR] |= (1 << (index % BITS_PER_CHAR));
    }
}

void clear_bit(BitArray *ba, int index) {
    if (index >= 0 && index < ba->size) {
        ba->bits[index / BITS_PER_CHAR] &= ~(1 << (index % BITS_PER_CHAR));
    }
}

int get_bit(BitArray *ba, int index) {
    if (index >= 0 && index < ba->size) {
        return (ba->bits[index / BITS_PER_CHAR] >> (index % BITS_PER_CHAR)) & 1;
    }
    return 0;
}

void assign_bit(BitArray *ba, int index, int value) {
    if (value) {
        set_bit(ba, index);
    } else {
        clear_bit(ba, index);
    }
}

int test_bit(BitArray *ba, int index) {
    return get_bit(ba, index);
}

int main(void) {
    int size = 100;
    BitArray *ba = bit_array_create(size);
    
    set_bit(ba, 5);
    set_bit(ba, 10);
    set_bit(ba, 50);
    
    printf("Bit 5: %d\n", test_bit(ba, 5));
    printf("Bit 10: %d\n", test_bit(ba, 10));
    printf("Bit 50: %d\n", test_bit(ba, 50));
    printf("Bit 7: %d\n", test_bit(ba, 7));
    
    clear_bit(ba, 10);
    printf("After clearing, Bit 10: %d\n", test_bit(ba, 10));
    
    bit_array_destroy(ba);
    
    return 0;
}
