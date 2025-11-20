#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef TEST_MODE
#include "math_utils.h"
#else
unsigned long long num_to_fibo_mask (unsigned long long num, unsigned long long* min_fibo) {
    if(num == 0) {
        if (min_fibo != NULL) {
            *min_fibo = 0;
        }
        return 0;
    }

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
            if (num == 0) {
                if (min_fibo != NULL) *min_fibo = b;
                break;
            }
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
#endif

int next_turn(int total, int possible) {
    assert(total > 0 && possible > 0);
    if (possible >= total) return total;

    int result = 1;
    unsigned long long min_fibo = 0;
    num_to_fibo_mask(total, &min_fibo);

    if ((int)min_fibo <= possible) {
        result = (int)min_fibo;
    }

    return result;
}

#ifdef TEST_MODE
int main()
{
    int n, q, res;
    res = scanf("%d%d", &n, &q);
    assert(res == 2);
    n = next_turn(n, q);
    printf("%d\n", n);
    return 0;
}
#endif