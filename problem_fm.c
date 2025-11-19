#include "stdio.h"
#include "assert.h"

struct Matrix {
    unsigned arr[4];
};

static long long fast_mult_mod(unsigned a, unsigned b, unsigned mod) {
    unsigned long long result = 0;
    a %= mod;

    while (b) {
        if (b % 2 != 0) {
            result = (result + a) % mod;
        }
        a = (a + a) % mod;
        b /= 2;
    }
    return result;
}

static struct Matrix mult_mtrx_mod(const struct Matrix mtrx1, const struct Matrix mtrx2, unsigned m) {

    struct Matrix result = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            unsigned s = 0;
            for (int k = 0; k < 2; ++k) {
                s = (s + fast_mult_mod(mtrx1.arr[2 * i + k], mtrx2.arr[2 * k + j], m)) % m;
            }
            result.arr[2 * i + j] = s;
        }
    }
    return result;
}

static struct Matrix pow_mtrx(struct Matrix mtrx, unsigned n, unsigned m) {
    struct Matrix result = (struct Matrix){1, 0, 0, 1};
    while (n) {
        if (n % 2 != 0) {
            result = mult_mtrx_mod(result, mtrx, m);
        }
        mtrx = mult_mtrx_mod(mtrx, mtrx, m);
        n /= 2;
    }
    return result;
}

unsigned get_fibo_fast(unsigned n, unsigned mod) {
    struct Matrix mtrx = {1, 1, 1, 0};
    return pow_mtrx(mtrx, n, mod).arr[1];
}

int get_fibo_simple(int n, int mod) {
    assert(n >= 0 && mod > 0);
    if(n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int a = 1;
    int b = 1;

    for(; n > 2 ;) {
        int temp = (a + b) % mod;
        a = b;
        b = temp;
        --n;

    }
    return b;
}

// int main(void) {
//     int n, mod;
//     scanf("%d %d", &n, &mod);
//     printf("%u\n", fibo_matrix_mult(n, mod));
//     return 0;
// }
