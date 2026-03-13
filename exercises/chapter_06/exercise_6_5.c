#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void eratosthenes_bitarray(int limit) {
    if (limit < 2) return;
    
    BitArray *sieve = bit_array_create(limit + 1);
    
    for (int i = 2; i <= limit; i++) {
        set_bit(sieve, i);
    }
    
    for (int i = 2; i * i <= limit; i++) {
        if (get_bit(sieve, i)) {
            for (int j = i * i; j <= limit; j += i) {
                clear_bit(sieve, j);
            }
        }
    }
    
    printf("Prime numbers up to %d:\n", limit);
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (get_bit(sieve, i)) {
            printf("%d ", i);
            count++;
            if (count % 10 == 0) printf("\n");
        }
    }
    printf("\nTotal: %d primes\n", count);
    
    bit_array_destroy(sieve);
}

int main(void) {
    eratosthenes_bitarray(100);
    return 0;
}
