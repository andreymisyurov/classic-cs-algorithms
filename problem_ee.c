#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long gcd_r(long long x, long long y, long long *a, long long *b) {
  if (y == 0) {
    *a = 1;
    *b = 0;
    return x;
  }

  long long a1, b1;
  long long d = gcd_r(y, x % y, &a1, &b1);

  *a = b1;
  *b = a1 - (x / y) * b1;

  return d;
}

long long gcd(long long x, long long y, long long *a, long long *b) {
  long long q = 0;
  long long a0 = 1, a1 = 0, b0 = 0, b1 = 1;
  long long temp_a, temp_b;

  do {
    temp_a = a0 - x / y * a1;
    temp_b = b0 - x / y * b1;
    a0 = a1;
    b0 = b1;
    a1 = temp_a;
    b1 = temp_b;

    q = x % y;
    x = y;
    y = q;
  } while (q);

  *a = a0;
  *b = b0;
  return x;
}

int main(void) {
  int x = 0;
  int y = 0;
  int check = scanf("%d %d", &x, &y);
  if (check != 2 || y == 0) {
    abort();
  }
  char flag = 0;
  if (x < 0) {
    x = -x;
    flag |= 1;
  }
  if (y < 0) {
    y = -y;
    flag |= 2;
  }
  if (x < y) {
    long long temp = x;
    x = y;
    y = temp;
    flag |= 4;
  }
  long long a, b;
  long long d = gcd(x, y, &a, &b);
  if ((flag & 4) != 0) {
    long long temp = a;
    a = b;
    b = temp;
  }
  if ((flag & 2) != 0) b = -b;
  if ((flag & 1) != 0) a = -a;
  printf("%lld %lld %lld\n", a, b, d);
  return 0;
}
