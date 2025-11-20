#include <assert.h>

#include "stdio.h"

void print_num(unsigned x, unsigned y) {
  if (x == 0) return;
  print_num(x / y, y);
  printf("%d", x % y);
}

int main(void) {
  unsigned x, y;
  scanf("%u %u", &x, &y);
  assert(y > 1);
  assert(y < 11);
  assert(x > 0);

  print_num(x, y);
  printf("\n");
  return 0;
}