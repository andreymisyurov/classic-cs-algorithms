#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long sum_fibo(unsigned long long num);
unsigned fibo_matrix_mult(unsigned n, unsigned mod);

int next_turn(unsigned total, unsigned possible) {
    if (possible >= total) return possible;

    int result = 1;
    unsigned long long mask_sum_fibo = sum_fibo(total);
    assert(mask_sum_fibo != 0);
    
    for(int i = 0; ; ++i) {
        if ((mask_sum_fibo & (1ULL << i)) != 0) {
            unsigned min_fibo = fibo_matrix_mult(i + 2, INT32_MAX);
            if (min_fibo <= possible) {
                result = min_fibo;
            }
            break;
        }
    }

    return result;
}

// int main()
// {
//     int n, q, res;

//     res = scanf("%d%d", &n, &q);
//     assert(res == 2);

//     n = next_turn(n, q);
//     printf("%d\n", n);

//     return 0;
// }
