#include "stdio.h"

long long fast_mult(long long a, long long b) {
    long long result = 0;
    while(a) {
        if (a % 2 != 0) {
            result = result + b;
        }
        b = b * 2;
        a /= 2;
    }
    return result;
}

long long fast_mult_mod(long long a, long long b, long long mod) {
    long long result = 0;
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

long long my_pow(long long a, long long b) {
    long long result = 1;
    while(b) {
        if (b % 2 != 0) {
            result = (1LL *result * a);
        }
        a = fast_mult(a, a);
        b /= 2;
    }
    return result;
}

long long my_pow_mod(long long a, long long b, long long mod) {
    long long result = 1 % mod;
    a %= mod;

    while (b) {
        if (b % 2 != 0) {
            result = fast_mult_mod(result, a, mod);
        }
        a = fast_mult_mod(a, a, mod);
        b /= 2;
    }

    return result;
}

long long super_pow_iter(long long a, long long b, int n) {
    a %= n;
    if (b == 0) return 1;
    if (b == 1) return a;

    long long exp = a;

    for (long long k = 2; k < b; ++k) {
        printf("gabella exp=%lld, a=%lld, b=%lld\n", exp, a, k);
        exp = my_pow(a, exp);
    }
    printf("gabella exp=%lld, a=%lld, b=%lld\n", exp, a, b);

    return my_pow_mod(a, exp, n);
}

int main(void) {
    long long a, b, n;                
    scanf("%lld %lld %lld", &a, &b, &n);
    printf("%lld\n", super_pow_iter(a, b, n));
    return 0;
}
