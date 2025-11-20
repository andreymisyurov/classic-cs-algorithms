#include <assert.h>
#include <stdlib.h>

#include "stdio.h"

static unsigned long long mult_peasant(unsigned long long a,
                                       unsigned long long b) {
  long long result = 0;
  while (b) {
    if (b % 2 != 0) {
      result = result + a;
    }
    a = a * 2;
    b /= 2;
  }
  return result;
}

long long mult_peasant_mod(unsigned long long a, unsigned long long b,
                           unsigned mod) {
  assert(mod != 0);

  unsigned long long result = 0;
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

static unsigned long long pow_bin(unsigned long long a, unsigned long long b) {
  unsigned long long result = 1;
  while (b) {
    if (b % 2 != 0) {
      result = mult_peasant(result, a);
    }
    a = mult_peasant(a, a);
    b /= 2;
  }
  return result;
}

static unsigned long long pow_bin_mod(unsigned long long a,
                                      unsigned long long b, unsigned mod) {
  assert(mod != 0);

  unsigned long long result = 1 % mod;
  a %= mod;

  while (b) {
    if (b % 2 != 0) {
      result = mult_peasant_mod(result, a, mod);
    }
    a = mult_peasant_mod(a, a, mod);
    b /= 2;
  }

  return result;
}

unsigned long long calc_tetration_mod(unsigned long long a,
                                      unsigned long long b, unsigned mod) {
  assert(mod != 0);

  a %= mod;
  if (b == 0) return 1;
  if (b == 1) return a;

  unsigned long long exp = a;

  for (unsigned long long k = 2; k < b; ++k) {
    exp = pow_bin(a, exp);
  }

  return pow_bin_mod(a, exp, mod);
}
