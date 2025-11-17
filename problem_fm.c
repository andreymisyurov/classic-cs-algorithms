#include "stdio.h"
#include "assert.h"

int fibo(int n, int mod) {
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

int main(void) {
    int n, mod;
    scanf("%d %d", &n, &mod);
    printf("%d\n", fibo(n, mod));
    return 0;
}