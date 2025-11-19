#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "fibo.h"

int next_turn(unsigned total, unsigned possible) {
    if (possible >= total) return possible;

    int result = 1;
    unsigned long long mask_sum_fibo = num_to_fibo_mask(total);
    assert(mask_sum_fibo != 0);
    
    for(int i = 0; ; ++i) {
        if ((mask_sum_fibo & (1ULL << i)) != 0) {
            unsigned min_fibo = get_fibo_fast(i + 2, UINT32_MAX);
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
