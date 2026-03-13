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

int count_primes(int limit) {
    if (limit < 2) return 0;
    
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
    
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (get_bit(sieve, i)) {
            count++;
        }
    }
    
    bit_array_destroy(sieve);
    return count;
}

int main(void) {
    int limits[] = {100, 1000, 10000, 100000, 1000000};
    int num_limits = sizeof(limits) / sizeof(limits[0]);
    
    printf("Prime distribution analysis:\n");
    printf("%-10s %-10s %-15s %-15s\n", "N", "Primes", "N/log(N)", "Ratio");
    printf("------------------------------------------------\n");
    
    for (int i = 0; i < num_limits; i++) {
        int n = limits[i];
        int primes = count_primes(n);
        double n_log_n = n / log(n);
        double ratio = primes / n_log_n;
        
        printf("%-10d %-10d %-15.2f %-15.4f\n", n, primes, n_log_n, ratio);
    }
    
    printf("\nNote: As N increases, the ratio approaches 1,\n");
    printf("confirming the Prime Number Theorem: pi(N) ~ N/log(N)\n");
    
    return 0;
}
