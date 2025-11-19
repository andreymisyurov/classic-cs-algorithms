#ifndef FIBO_H
#define FIBO_H

#include <stdint.h>

// From problem_sf.c
unsigned long long num_to_fibo_mask(unsigned long long num);

// From problem_fm.c
unsigned get_fibo_fast(unsigned n, unsigned mod);

// From problem_hwf.c
int next_turn(unsigned total, unsigned possible);

#endif