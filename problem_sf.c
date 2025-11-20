#include "stdio.h"
#include <assert.h>

// func for test output only
static void __attribute__((unused)) print_num_to_2ss(unsigned long long num) {
    for(int i = 63, flag = 0; i >= 0; --i) {
        if(num & (1ULL << i)) {
            printf("1");
            flag = 1;
        } else {
            if(flag) printf("0");
        }
    }
    printf("\n");
}

unsigned long long num_to_fibo_mask (unsigned long long num) {
    unsigned long long result = 0;
    unsigned long long a = 1;
    unsigned long long b = 1;
    int bit_index = 0; // bit 0 -> F2, bit 1 -> F3, etc. (bit i = F(i+2))

    // grow Fibonacci numbers up to the largest F <= num
    for(unsigned long long next; ; ) {
        next = a + b;
        if (next <= num) {
            a = b;
            b = next;
            ++bit_index;
        } else {
            break;
        }
    }

    assert(bit_index < 64);

    // walk Fibonacci numbers down and set bits in result
    for(unsigned long long prev; num != 0 ;) {
        if(b <= num) { // take this Fibonacci number into the sum
            num -= b;
            result = result | 1ULL << bit_index;
            prev = b - a;
            b = a;
            a = prev;
            --bit_index;
            prev = b - a;
            b = a;
            a = prev;
            --bit_index;
        } else { // this Fibonacci is too big, go to the previous one
            prev = b - a;
            b = a;
            a = prev;
            --bit_index;
        }
    }

    return result;
}
