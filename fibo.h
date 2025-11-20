#ifndef FIBO_H
#define FIBO_H

struct Matrix {
    unsigned arr[4];
};

// problem_rps.c
unsigned long long mult_peasant_mod(unsigned long long a, unsigned long long b, unsigned mod);
unsigned long long calc_tetration_mod(unsigned long long a, unsigned long long b, unsigned mod);

// problem_mf.c
struct Matrix mult_matrix_mod(const struct Matrix m1, const struct Matrix m2, unsigned mod);
struct Matrix pow_matrix_mod(struct Matrix m, unsigned long long n, unsigned mod);

// problem_sf.c
unsigned long long num_to_fibo_mask(unsigned long long num);

// problem_fm.c
unsigned get_fibo_fast(unsigned n, unsigned mod);

// problem_pp.c
long long get_fibo_pisano(long long n, long long mod, long long* pisano_len);

// problem_hwf.c
int next_turn(unsigned total, unsigned possible);

#endif