#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long gcd(long long x, long long y) {
    assert (y > 0);

    long long q = 0;
    do{
        q = x % y;
        x = y;
        y = q;
    }
    while(q);
    return x;
}

long long gcd_r(long long x, 
                       long long y) {
    if (y > x) {
        long long temp = x;
        x = y;
        y = temp;
    }
    if(y == 0) return x;
    return gcd_r(y, x%y);
}

int main(void) {
    long long x = 0, y = 0, g;
    int res;

    res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    
    if (y > x) {
        long long temp = x;
        x = y;
        y = temp;
    }
    printf("%lld\n", gcd(x , y));
    return 0;
}
