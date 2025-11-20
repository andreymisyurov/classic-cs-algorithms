#include "stdio.h"
#include "assert.h"
#include "stdlib.h"

long long get_fibo_pisano(long long n, long long mod, long long* pizo) {
    assert(mod > 0);
    assert(n >= 0);
    assert(pizo != NULL);

    long long a = 1, b = 1;
    long long flag_pizo = 0, current_n = 2;
    long long fibo = 0;

    for(; flag_pizo < 2 ;) {
        long long next = (a + b) % mod;
        a = b;
        b = next;
        ++current_n;

        if (current_n == n) fibo = b;

        if (a == 0 && b == 1) ++flag_pizo;
        if (flag_pizo == 1) ++(*pizo);
    }

    if (fibo == 0) {
        n %= *pizo;

        a = 1;
        b = 1;
        current_n = 2;
        for (; current_n < n;) {
            long long next = (a + b) % mod;
            a = b;
            b = next;
            ++current_n;
            if (current_n == n) fibo = b;
        }

        if(n == 1 || n == 2) fibo = 1;
    }
    return fibo;
}
