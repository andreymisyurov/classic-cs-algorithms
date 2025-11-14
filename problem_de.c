#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long gcd(long long x, long long y, long long *a, long long *b) {

    long long q = 0;
    long long a0 = 1, a1 = 0, b0 = 0, b1 = 1;
    long long temp_a, temp_b;
    
    do{
        temp_a = a0 - x/y*a1;
        temp_b = b0 - x/y*b1;
        a0 = a1;
        b0 = b1;
        a1 = temp_a;
        b1 = temp_b;

        q = x % y;
        x = y;
        y = q;
    }
    while(q);

    *a = a0;
    *b = b0;
    return x;
}

int main(void) {
    long long a = 0;
    long long b = 0;
    long long c = 0;
    int check = scanf("%lld %lld %lld", &a, &b, &c);
    if(check != 3) {
        abort();
    }
    char flag = 0;
    if (a < 0) {
        a = -a;
        flag |= 1;
    }
    if (b < 0) {
        b = -b;
        flag |= 2;
    }
    if (a < b) {
        long long temp = a;
        a = b;
        b = temp;
        flag |= 4;
    }
    long long x, y;
    long long d = gcd(a, b, &x, &y);
    if (c % d != 0) {
        printf("NONE\n");
        return 0;
    }
    if ((flag & 4) != 0) {
        long long temp = x;
        x = y;
        y = temp;
    }

    if ((flag & 1) != 0) x = -x;
    if ((flag & 2) != 0) y = -y;

    printf("%lld %lld\n", x * c / d, y * c / d);

    return 0;
}
