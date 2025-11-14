#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x = 0;
    int y = 0;
    int check = scanf("%d %d", &x, &y);
    if(check != 2 || y == 0) {
        abort();
    }

    int q = 0;
    do {
        printf("%d ", x / y);
        q = x % y;
        x = y;
        y = q;
    } while(q);

    return 0;
}
