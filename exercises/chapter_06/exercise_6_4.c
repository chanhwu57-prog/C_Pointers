#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eratosthenes(int limit) {
    if (limit < 2) return;
    
    char *sieve = malloc(limit + 1);
    memset(sieve, 1, limit + 1);
    
    sieve[0] = sieve[1] = 0;
    
    for (int i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = 0;
            }
        }
    }
    
    printf("Prime numbers up to %d:\n", limit);
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (sieve[i]) {
            printf("%d ", i);
            count++;
            if (count % 10 == 0) printf("\n");
        }
    }
    printf("\nTotal: %d primes\n", count);
    
    free(sieve);
}

int main(void) {
    eratosthenes(100);
    return 0;
}
