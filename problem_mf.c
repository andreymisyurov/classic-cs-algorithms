#include "stdio.h"
#include "fibo.h"


static void __attribute__((unused)) print_matrix(struct Matrix mtrx) {
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            printf("%u ", mtrx.arr[2 * i + j]);
    printf("\n");
}

struct Matrix mult_matrix_mod(const struct Matrix mtrx1, const struct Matrix mtrx2, unsigned m) {

    struct Matrix result = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            unsigned s = 0;
            for (int k = 0; k < 2; ++k) {
                s = (s + mult_peasant_mod(mtrx1.arr[2 * i + k], mtrx2.arr[2 * k + j], m)) % m;
            }
            result.arr[2 * i + j] = s;
        }
    }

    return result;
}

struct Matrix pow_matrix_mod(struct Matrix m, unsigned long long n, unsigned mod) {
    struct Matrix result = (struct Matrix){1, 0, 0, 1};
    while (n) {
        if (n % 2 != 0) {
            result = mult_matrix_mod(result, m, mod);
        }
        m = mult_matrix_mod(m, m, mod);
        n /= 2;
    }
    return result;
}
