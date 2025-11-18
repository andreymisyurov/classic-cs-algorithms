#include "stdio.h"

struct Matrix {
    unsigned arr[4];
};

void print_matrix(struct Matrix mtrx) {
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            printf("%u ", mtrx.arr[2 * i + j]);
    printf("\n");
}

long long fast_mult_mod(unsigned a, unsigned b, unsigned mod) {
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

struct Matrix mult_mtrx_mod(const struct Matrix mtrx1, const struct Matrix mtrx2, unsigned m) {

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

struct Matrix pow_mtrx(struct Matrix mtrx, unsigned n, unsigned m) {
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

int main(void) {
    struct Matrix matrix = {1,1,1,0};
    unsigned n, m;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            scanf("%u ", &matrix.arr[2 * i + j]);
        }
    }
    scanf("%u %u", &n, &m);
    print_matrix(pow_mtrx(matrix, n, m));
    return 0;
}
