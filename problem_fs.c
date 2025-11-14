#include "stdio.h"

void print_sf(long long unsigned* num, long long unsigned fact) {
    static long long unsigned count = 0;
    if (*num < fact) {
        return;
    }
    print_sf(num, fact * ++count);
    --count;
    if (count == 0) return;

    long long unsigned temp = 0;

    while(*num >= fact) {
        *num -=fact;
        ++temp;
    }
    printf("%lld.", temp);
}

int main(void) {
    long long unsigned num;
    scanf("%llu", &num);

    print_sf(&num, 1);
    return 0;
}
