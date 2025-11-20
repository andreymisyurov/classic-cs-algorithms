#include <check.h>
#include <stdio.h>

#include "math_utils.h"

// TCase: Num_To_Fibo_Mask

// [num_to_fibo_mask] Val: 0 -> mask: 0, min_fibo: 0
START_TEST(test_num_to_fibo_mask_0) {
  unsigned long long min_fibo = 123;  // Garbage
  ck_assert_int_eq(num_to_fibo_mask(0, &min_fibo), 0);
  ck_assert_int_eq(min_fibo, 0);
}
END_TEST

// [num_to_fibo_mask] Val: 11 (10100 -> 8 + 3 -> 8 + 2 + 1 NO Zeckendorf: 8 + 3
// is not fibo sum) 11 = 8 + 3. 3 = 2 + 1. So 11 = 8 + 3? No. 3 is F4.
// Zeckendorf for 11:
// F6=8. 11-8=3.
// F4=3. 3-3=0.
// Sum: 8 + 3. Mask: (1<<4) | (1<<2) = 16 + 4 = 20. Correct.
// Min fibo taken is 3.
START_TEST(test_num_to_fibo_mask_11_with_min) {
  unsigned long long min_fibo = 0;
  ck_assert_int_eq(num_to_fibo_mask(11, &min_fibo), 20);
  ck_assert_int_eq(min_fibo, 3);
}
END_TEST

// [num_to_fibo_mask] Val: 10 (8 + 2) -> min_fibo: 2
START_TEST(test_num_to_fibo_mask_10_with_min) {
  unsigned long long min_fibo = 0;
  ck_assert_int_eq(num_to_fibo_mask(10, &min_fibo), 18);  // 16 + 2
  ck_assert_int_eq(min_fibo, 2);
}
END_TEST

// [num_to_fibo_mask] Val: 13 (F7) -> mask: 1<<5 = 32. min_fibo: 13
START_TEST(test_num_to_fibo_mask_13_with_min) {
  unsigned long long min_fibo = 0;
  ck_assert_int_eq(num_to_fibo_mask(13, &min_fibo), 32);
  ck_assert_int_eq(min_fibo, 13);
}
END_TEST

// [num_to_fibo_mask] Val: 1 -> mask: 1 (0b1)
START_TEST(test_num_to_fibo_mask_1) {
  ck_assert_int_eq(num_to_fibo_mask(1, NULL), 1);
}
END_TEST

// [num_to_fibo_mask] Val: 4 -> mask: 5 (0b101)
START_TEST(test_num_to_fibo_mask_4) {
  ck_assert_int_eq(num_to_fibo_mask(4, NULL), 5);
}
END_TEST

// [num_to_fibo_mask] Val: 11 -> mask: 20 (0b10100)
START_TEST(test_num_to_fibo_mask_11) {
  ck_assert_int_eq(num_to_fibo_mask(11, NULL), 20);
}
END_TEST

// [num_to_fibo_mask] Val: 20 -> mask: 42 (0b101010)
START_TEST(test_num_to_fibo_mask_20) {
  ck_assert_int_eq(num_to_fibo_mask(20, NULL), 42);
}
END_TEST

// [num_to_fibo_mask] Val: 123456 -> mask: 16814592
START_TEST(test_num_to_fibo_mask_123456) {
  ck_assert_int_eq(num_to_fibo_mask(123456, NULL), 16814592);
}
END_TEST

// [num_to_fibo_mask] Val: 654321 -> mask: 152059905
START_TEST(test_num_to_fibo_mask_654321) {
  ck_assert_int_eq(num_to_fibo_mask(654321, NULL), 152059905);
}
END_TEST

// [num_to_fibo_mask] Val: 101010101 -> mask: 182805727745
START_TEST(test_num_to_fibo_mask_101010101) {
  ck_assert_int_eq(num_to_fibo_mask(101010101, NULL), 182805727745);
}
END_TEST

// [num_to_fibo_mask] Val: 202020202 -> mask: 594050424962
START_TEST(test_num_to_fibo_mask_202020202) {
  ck_assert_int_eq(num_to_fibo_mask(202020202, NULL), 594050424962);
}
END_TEST

// [num_to_fibo_mask] Val: 1234567890 -> mask: 8977825023301
START_TEST(test_num_to_fibo_mask_1234567890) {
  ck_assert_int_eq(num_to_fibo_mask(1234567890, NULL), 8977825023301);
}
END_TEST

// [num_to_fibo_mask] Val: 1000000000 -> mask: 5536391137833
START_TEST(test_num_to_fibo_mask_1000000000) {
  ck_assert_int_eq(num_to_fibo_mask(1000000000, NULL), 5536391137833);
}
END_TEST

// TCase: Game Logic

// [next_turn] Total: 11, Max: 4 -> 3
START_TEST(test_next_turn_11_4) { ck_assert_int_eq(next_turn(11, 4), 3); }
END_TEST

// [next_turn] Total: 8, Max: 5 -> 1
START_TEST(test_next_turn_8_5) { ck_assert_int_eq(next_turn(8, 5), 1); }
END_TEST

// [next_turn] Total: 5, Max: 3 -> 1
START_TEST(test_next_turn_5_3) { ck_assert_int_eq(next_turn(5, 3), 1); }
END_TEST

// [next_turn] Total: 10, Max: 9 -> 2
START_TEST(test_next_turn_10_9) { ck_assert_int_eq(next_turn(10, 9), 2); }
END_TEST

// [next_turn] Total: 100, Max: 99 -> 3
START_TEST(test_next_turn_100_99) { ck_assert_int_eq(next_turn(100, 99), 3); }
END_TEST

// [next_turn] Total: 1000, Max: 999 -> 13
START_TEST(test_next_turn_1000_999) {
  ck_assert_int_eq(next_turn(1000, 999), 13);
}
END_TEST

// [next_turn] Total: 10000, Max: 9 -> 2
START_TEST(test_next_turn_10000_9) { ck_assert_int_eq(next_turn(10000, 9), 2); }
END_TEST

// [next_turn] Total: 100000, Max: 8 -> 1
START_TEST(test_next_turn_100000_8) {
  ck_assert_int_eq(next_turn(100000, 8), 1);
}
END_TEST

// [next_turn] Total: 1000000, Max: 1000 -> 55
START_TEST(test_next_turn_1000000_1000) {
  ck_assert_int_eq(next_turn(1000000, 1000), 55);
}
END_TEST

// [next_turn] Total: 500500501, Max: 111 -> 89
START_TEST(test_next_turn_500500501_111) {
  ck_assert_int_eq(next_turn(500500501, 111), 89);
}
END_TEST

// [next_turn] Total: 500500501, Max: 11 -> 1
START_TEST(test_next_turn_500500501_11) {
  ck_assert_int_eq(next_turn(500500501, 11), 1);
}
END_TEST

// [next_turn] Total: 4, Max: 3 -> 1
START_TEST(test_next_turn_4_3) { ck_assert_int_eq(next_turn(4, 3), 1); }
END_TEST

// TCase: Fast_Fibo

// [get_fibo_fast] N: 0, Mod: 10 -> 0
START_TEST(test_fibo_fast_0_10) { ck_assert_int_eq(get_fibo_fast(0, 10), 0); }
END_TEST

// [get_fibo_fast] N: 90, Mod: 12 -> 4
START_TEST(test_fibo_fast_90_12) { ck_assert_int_eq(get_fibo_fast(90, 12), 4); }
END_TEST

// [get_fibo_fast] N: 121, Mod: 13 -> 8
START_TEST(test_fibo_fast_121_13) {
  ck_assert_int_eq(get_fibo_fast(121, 13), 8);
}
END_TEST

// [get_fibo_fast] N: 152, Mod: 14 -> 7
START_TEST(test_fibo_fast_152_14) {
  ck_assert_int_eq(get_fibo_fast(152, 14), 7);
}
END_TEST

// [get_fibo_fast] N: 183, Mod: 15 -> 7
START_TEST(test_fibo_fast_183_15) {
  ck_assert_int_eq(get_fibo_fast(183, 15), 7);
}
END_TEST

// [get_fibo_fast] N: 214, Mod: 16 -> 15
START_TEST(test_fibo_fast_214_16) {
  ck_assert_int_eq(get_fibo_fast(214, 16), 15);
}
END_TEST

// [get_fibo_fast] N: 245, Mod: 17 -> 13
START_TEST(test_fibo_fast_245_17) {
  ck_assert_int_eq(get_fibo_fast(245, 17), 13);
}
END_TEST

// [get_fibo_fast] N: 500, Mod: 11 -> 0
START_TEST(test_fibo_fast_500_11) {
  ck_assert_int_eq(get_fibo_fast(500, 11), 0);
}
END_TEST

// [get_fibo_fast] N: 1000, Mod: 35 -> 0
START_TEST(test_fibo_fast_1000_35) {
  ck_assert_int_eq(get_fibo_fast(1000, 35), 0);
}
END_TEST

// [get_fibo_fast] N: 2000, Mod: 49 -> 42
START_TEST(test_fibo_fast_2000_49) {
  ck_assert_int_eq(get_fibo_fast(2000, 49), 42);
}
END_TEST

// TCase: Pisano

// [get_fibo_pisano] N: 0, Mod: 10 -> F: 0, Pizo: 60
START_TEST(test_get_fibo_pisano_0_mod_10) {
  long long pizo = 0;
  ck_assert_int_eq(get_fibo_pisano(0, 10, &pizo), 0);
  ck_assert_int_eq(pizo, 60);
}
END_TEST

// [get_fibo_pisano] N: 1, Mod: 10 -> F: 1, Pizo: 60
START_TEST(test_get_fibo_pisano_1_mod_10) {
  long long pizo = 0;
  ck_assert_int_eq(get_fibo_pisano(1, 10, &pizo), 1);
  ck_assert_int_eq(pizo, 60);
}
END_TEST

// [get_fibo_pisano] N: 10, Mod: 10 -> F: 5, Pizo: 60
START_TEST(test_get_fibo_pisano_10_mod_10) {
  long long pizo = 0;
  ck_assert_int_eq(get_fibo_pisano(10, 10, &pizo), 5);
  ck_assert_int_eq(pizo, 60);
}
END_TEST

// [get_fibo_pisano] N: 9000, Mod: 120 -> F: 0, Pizo: 120
START_TEST(test_get_fibo_pisano_9000_mod_120) {
  long long pizo = 0;
  ck_assert_int_eq(get_fibo_pisano(9000, 120, &pizo), 0);
  ck_assert_int_eq(pizo, 120);
}
END_TEST

// [get_fibo_pisano] N: 121000, Mod: 1300 -> F: 1275, Pizo: 2100
START_TEST(test_get_fibo_pisano_121000_mod_1300) {
  long long pizo = 0;
  ck_assert_int_eq(get_fibo_pisano(121000, 1300, &pizo), 1275);
  ck_assert_int_eq(pizo, 2100);
}
END_TEST

// [get_fibo_pisano] N: 183111111, Mod: 152222 -> F: 71658, Pizo: 21840
START_TEST(test_get_fibo_pisano_183111111_mod_152222) {
  long long pizo = 0;
  ck_assert_int_eq(get_fibo_pisano(183111111, 152222, &pizo), 71658);
  ck_assert_int_eq(pizo, 21840);
}
END_TEST

// [get_fibo_pisano] N: 21433333333, Mod: 167890 -> F: 128323, Pizo: 127920
START_TEST(test_get_fibo_pisano_21433333333_mod_167890) {
  long long pizo = 0;
  ck_assert_int_eq(get_fibo_pisano(21433333333, 167890, &pizo), 128323);
  ck_assert_int_eq(pizo, 127920);
}
END_TEST

// [get_fibo_pisano] N: 500500500500500, Mod: 1111111 -> F: 912200, Pizo: 19754
START_TEST(test_get_fibo_pisano_500500500500500_mod_1111111) {
  long long pizo = 0;
  ck_assert_int_eq(get_fibo_pisano(500500500500500, 1111111, &pizo), 912200);
  ck_assert_int_eq(pizo, 19754);
}
END_TEST

// TCase: Tetration (Super Power)

// [calc_tetration_mod] A: 2, B: 1, Mod: 10 -> 2
START_TEST(test_tetration_2_1_10) {
  ck_assert_int_eq(calc_tetration_mod(2, 1, 10), 2);
}
END_TEST

// [calc_tetration_mod] A: 2, B: 4, Mod: 10 -> 6
START_TEST(test_tetration_2_4_10) {
  ck_assert_int_eq(calc_tetration_mod(2, 4, 10), 6);
}
END_TEST

// [calc_tetration_mod] A: 2, B: 5, Mod: 10 -> 6
START_TEST(test_tetration_2_5_10) {
  ck_assert_int_eq(calc_tetration_mod(2, 5, 10), 6);
}
END_TEST

// [calc_tetration_mod] A: 3, B: 4, Mod: 10 -> 7
START_TEST(test_tetration_3_4_10) {
  ck_assert_int_eq(calc_tetration_mod(3, 4, 10), 7);
}
END_TEST

// [calc_tetration_mod] A: 4, B: 3, Mod: 10 -> 6
START_TEST(test_tetration_4_3_10) {
  ck_assert_int_eq(calc_tetration_mod(4, 3, 10), 6);
}
END_TEST

// [calc_tetration_mod] A: 4, B: 3, Mod: 2 -> 0
START_TEST(test_tetration_4_3_2) {
  ck_assert_int_eq(calc_tetration_mod(4, 3, 2), 0);
}
END_TEST

// [calc_tetration_mod] A: 5, B: 3, Mod: 10 -> 5
START_TEST(test_tetration_5_3_10) {
  ck_assert_int_eq(calc_tetration_mod(5, 3, 10), 5);
}
END_TEST

// [calc_tetration_mod] A: 5, B: 3, Mod: 2 -> 1
START_TEST(test_tetration_5_3_2) {
  ck_assert_int_eq(calc_tetration_mod(5, 3, 2), 1);
}
END_TEST

// [calc_tetration_mod] A: 6, B: 3, Mod: 10 -> 6
START_TEST(test_tetration_6_3_10) {
  ck_assert_int_eq(calc_tetration_mod(6, 3, 10), 6);
}
END_TEST

// [calc_tetration_mod] A: 6, B: 3, Mod: 2 -> 0
START_TEST(test_tetration_6_3_2) {
  ck_assert_int_eq(calc_tetration_mod(6, 3, 2), 0);
}
END_TEST

// TCase: Matrix Operations

// [mult_matrix_mod] [[1 1][1 0]] * [[1 1][1 0]] %10 -> [[2 1][1 1]]
START_TEST(test_mult_matrix_mod_1110_10) {
  struct Matrix mtrx = {1, 1, 1, 0};
  mtrx = mult_matrix_mod(mtrx, mtrx, 10);
  ck_assert_int_eq(mtrx.arr[0], 2);
  ck_assert_int_eq(mtrx.arr[1], 1);
  ck_assert_int_eq(mtrx.arr[2], 1);
  ck_assert_int_eq(mtrx.arr[3], 1);
}
END_TEST

// [mult_matrix_mod] [[2 1][1 1]]^2 %10 -> [[5 3][3 2]]
START_TEST(test_mult_matrix_mod_2111_10) {
  struct Matrix mtrx = {2, 1, 1, 1};
  mtrx = mult_matrix_mod(mtrx, mtrx, 10);
  ck_assert_int_eq(mtrx.arr[0], 5);
  ck_assert_int_eq(mtrx.arr[1], 3);
  ck_assert_int_eq(mtrx.arr[2], 3);
  ck_assert_int_eq(mtrx.arr[3], 2);
}
END_TEST

// [pow_matrix_mod] FibMatrix^5 %100 -> [[8 5][5 3]]
START_TEST(test_pow_matrix_mod_1110_5_100) {
  struct Matrix mtrx = {1, 1, 1, 0};
  mtrx = pow_matrix_mod(mtrx, 5, 100);
  ck_assert_int_eq(mtrx.arr[0], 8);
  ck_assert_int_eq(mtrx.arr[1], 5);
  ck_assert_int_eq(mtrx.arr[2], 5);
  ck_assert_int_eq(mtrx.arr[3], 3);
}
END_TEST

// [pow_matrix_mod] FibMatrix^2 %10 -> [[2 1][1 1]]
START_TEST(test_pow_matrix_mod_1110_2_10) {
  struct Matrix mtrx = {1, 1, 1, 0};
  mtrx = pow_matrix_mod(mtrx, 2, 10);
  ck_assert_int_eq(mtrx.arr[0], 2);
  ck_assert_int_eq(mtrx.arr[1], 1);
  ck_assert_int_eq(mtrx.arr[2], 1);
  ck_assert_int_eq(mtrx.arr[3], 1);
}
END_TEST

// [pow_matrix_mod] FibMatrix^20 %10 -> [[6 5][5 1]]
START_TEST(test_pow_matrix_mod_1110_20_10) {
  struct Matrix mtrx = {1, 1, 1, 0};
  mtrx = pow_matrix_mod(mtrx, 20, 10);
  ck_assert_int_eq(mtrx.arr[0], 6);
  ck_assert_int_eq(mtrx.arr[1], 5);
  ck_assert_int_eq(mtrx.arr[2], 5);
  ck_assert_int_eq(mtrx.arr[3], 1);
}
END_TEST

// [pow_matrix_mod] FibMatrix^20000 %64 -> [[34 5][5 29]]
START_TEST(test_pow_matrix_mod_1110_20000_64) {
  struct Matrix mtrx = {1, 1, 1, 0};
  mtrx = pow_matrix_mod(mtrx, 20000, 64);
  ck_assert_int_eq(mtrx.arr[0], 34);
  ck_assert_int_eq(mtrx.arr[1], 5);
  ck_assert_int_eq(mtrx.arr[2], 5);
  ck_assert_int_eq(mtrx.arr[3], 29);
}
END_TEST

// [pow_matrix_mod] [[1 2][3 0]]^20000 %64 -> [[39 26][39 26]]
START_TEST(test_pow_matrix_mod_1230_20000_64) {
  struct Matrix mtrx = {1, 2, 3, 0};
  mtrx = pow_matrix_mod(mtrx, 20000, 64);
  ck_assert_int_eq(mtrx.arr[0], 39);
  ck_assert_int_eq(mtrx.arr[1], 26);
  ck_assert_int_eq(mtrx.arr[2], 39);
  ck_assert_int_eq(mtrx.arr[3], 26);
}
END_TEST

// [pow_matrix_mod] FibMatrix^21 %13 -> [[5 0][0 5]]
START_TEST(test_pow_matrix_mod_1110_21_13) {
  struct Matrix mtrx = {1, 1, 1, 0};
  mtrx = pow_matrix_mod(mtrx, 21, 13);
  ck_assert_int_eq(mtrx.arr[0], 5);
  ck_assert_int_eq(mtrx.arr[1], 0);
  ck_assert_int_eq(mtrx.arr[2], 0);
  ck_assert_int_eq(mtrx.arr[3], 5);
}
END_TEST

// [pow_matrix_mod] [[1 1][0 1]]^21 %13 -> [[1 8][0 1]]
START_TEST(test_pow_matrix_mod_1101_21_13) {
  struct Matrix mtrx = {1, 1, 0, 1};
  mtrx = pow_matrix_mod(mtrx, 21, 13);
  ck_assert_int_eq(mtrx.arr[0], 1);
  ck_assert_int_eq(mtrx.arr[1], 8);
  ck_assert_int_eq(mtrx.arr[2], 0);
  ck_assert_int_eq(mtrx.arr[3], 1);
}
END_TEST

// [pow_matrix_mod] [[1 0][1 1]]^21 %13 -> [[1 0][8 1]]
START_TEST(test_pow_matrix_mod_1011_21_13) {
  struct Matrix mtrx = {1, 0, 1, 1};
  mtrx = pow_matrix_mod(mtrx, 21, 13);
  ck_assert_int_eq(mtrx.arr[0], 1);
  ck_assert_int_eq(mtrx.arr[1], 0);
  ck_assert_int_eq(mtrx.arr[2], 8);
  ck_assert_int_eq(mtrx.arr[3], 1);
}
END_TEST

// [pow_matrix_mod] [[0 1][1 1]]^21 %13 -> [[5 0][0 5]]
START_TEST(test_pow_matrix_mod_0111_21_13) {
  struct Matrix mtrx = {0, 1, 1, 1};
  mtrx = pow_matrix_mod(mtrx, 21, 13);
  ck_assert_int_eq(mtrx.arr[0], 5);
  ck_assert_int_eq(mtrx.arr[1], 0);
  ck_assert_int_eq(mtrx.arr[2], 0);
  ck_assert_int_eq(mtrx.arr[3], 5);
}
END_TEST

// [pow_matrix_mod] [[1 2][3 4]]^20000000 %10 -> [[1 0][5 6]]
START_TEST(test_pow_matrix_mod_1234_20000000_10) {
  struct Matrix mtrx = {1, 2, 3, 4};
  mtrx = pow_matrix_mod(mtrx, 20000000, 10);
  ck_assert_int_eq(mtrx.arr[0], 1);
  ck_assert_int_eq(mtrx.arr[1], 0);
  ck_assert_int_eq(mtrx.arr[2], 5);
  ck_assert_int_eq(mtrx.arr[3], 6);
}
END_TEST

// TCase: Peasant Multiplication

// [mult_peasant_mod] A: 1000000007, B: 2, Mod: 1000000009 -> 2000000014 %
// 1000000009
START_TEST(test_mult_peasant_large) {
  unsigned mod = 1000000009;
  unsigned long long a = 1000000007ULL;
  unsigned long long b = 2ULL;
  ck_assert_int_eq(mult_peasant_mod(a, b, mod), (a * b) % mod);
}
END_TEST

// [mult_peasant_mod] A: 123, B: 456, Mod: 100 -> (123 * 456) % 100 = 88
START_TEST(test_mult_peasant_123_456_100) {
  ck_assert_int_eq(mult_peasant_mod(123, 456, 100), (123 * 456) % 100);
}
END_TEST

// [mult_peasant_mod] A: 0, B: 123, Mod: 7 -> 0
START_TEST(test_mult_peasant_0_123_7) {
  ck_assert_int_eq(mult_peasant_mod(0, 123, 7), 0);
}
END_TEST

// [mult_peasant_mod] A: 1, B: 1, Mod: 2 -> 1
START_TEST(test_mult_peasant_1_1_2) {
  ck_assert_int_eq(mult_peasant_mod(1, 1, 2), 1);
}
END_TEST

// [mult_peasant_mod] A: 999999999, B: 999999999, Mod: 1000000000 -> 999999999
START_TEST(test_mult_peasant_max_1000000000) {
  unsigned mod = 1000000000;
  unsigned long long a = 999999999ULL;
  unsigned long long b = 999999999ULL;
  ck_assert_int_eq(mult_peasant_mod(a, b, mod), (a * b) % mod);
}
END_TEST

Suite *create_num_to_fibo_suite(void) {
  Suite *s = suite_create("Zeckendorf (num->mask, min_fibo)");
  TCase *tc = tcase_create("Num_To_Fibo_Mask");
  tcase_add_test(tc, test_num_to_fibo_mask_0);
  tcase_add_test(tc, test_num_to_fibo_mask_11_with_min);
  tcase_add_test(tc, test_num_to_fibo_mask_10_with_min);
  tcase_add_test(tc, test_num_to_fibo_mask_13_with_min);
  tcase_add_test(tc, test_num_to_fibo_mask_1);
  tcase_add_test(tc, test_num_to_fibo_mask_4);
  tcase_add_test(tc, test_num_to_fibo_mask_11);
  tcase_add_test(tc, test_num_to_fibo_mask_20);
  tcase_add_test(tc, test_num_to_fibo_mask_123456);
  tcase_add_test(tc, test_num_to_fibo_mask_654321);
  tcase_add_test(tc, test_num_to_fibo_mask_101010101);
  tcase_add_test(tc, test_num_to_fibo_mask_202020202);
  tcase_add_test(tc, test_num_to_fibo_mask_1234567890);
  tcase_add_test(tc, test_num_to_fibo_mask_1000000000);
  suite_add_tcase(s, tc);
  return s;
}

Suite *create_game_logic_suite(void) {
  Suite *s = suite_create("Fibonacci Nim (Game)");
  TCase *tc = tcase_create("Game_Logic");
  tcase_add_test(tc, test_next_turn_11_4);
  tcase_add_test(tc, test_next_turn_8_5);
  tcase_add_test(tc, test_next_turn_5_3);
  tcase_add_test(tc, test_next_turn_10_9);
  tcase_add_test(tc, test_next_turn_100_99);
  tcase_add_test(tc, test_next_turn_1000_999);
  tcase_add_test(tc, test_next_turn_10000_9);
  tcase_add_test(tc, test_next_turn_100000_8);
  tcase_add_test(tc, test_next_turn_1000000_1000);
  tcase_add_test(tc, test_next_turn_500500501_111);
  tcase_add_test(tc, test_next_turn_500500501_11);
  tcase_add_test(tc, test_next_turn_4_3);
  suite_add_tcase(s, tc);
  return s;
}

Suite *create_fast_fibo_suite(void) {
  Suite *s = suite_create("Fast Fibonacci (Matrix)");
  TCase *tc = tcase_create("Fast_Fibo");
  tcase_add_test(tc, test_fibo_fast_0_10);
  tcase_add_test(tc, test_fibo_fast_90_12);
  tcase_add_test(tc, test_fibo_fast_121_13);
  tcase_add_test(tc, test_fibo_fast_152_14);
  tcase_add_test(tc, test_fibo_fast_183_15);
  tcase_add_test(tc, test_fibo_fast_214_16);
  tcase_add_test(tc, test_fibo_fast_245_17);
  tcase_add_test(tc, test_fibo_fast_500_11);
  tcase_add_test(tc, test_fibo_fast_1000_35);
  tcase_add_test(tc, test_fibo_fast_2000_49);
  suite_add_tcase(s, tc);
  return s;
}

Suite *create_pisano_suite(void) {
  Suite *s = suite_create("Pisano Period (mod m)");
  TCase *tc = tcase_create("Pisano");
  tcase_add_test(tc, test_get_fibo_pisano_0_mod_10);
  tcase_add_test(tc, test_get_fibo_pisano_1_mod_10);
  tcase_add_test(tc, test_get_fibo_pisano_10_mod_10);
  tcase_add_test(tc, test_get_fibo_pisano_9000_mod_120);
  tcase_add_test(tc, test_get_fibo_pisano_121000_mod_1300);
  tcase_add_test(tc, test_get_fibo_pisano_183111111_mod_152222);
  tcase_add_test(tc, test_get_fibo_pisano_21433333333_mod_167890);
  tcase_add_test(tc, test_get_fibo_pisano_500500500500500_mod_1111111);
  suite_add_tcase(s, tc);
  return s;
}

Suite *create_tetration_suite(void) {
  Suite *s = suite_create("Tetration (a^^b % m)");
  TCase *tc = tcase_create("Tetration");
  tcase_add_test(tc, test_tetration_2_1_10);
  tcase_add_test(tc, test_tetration_2_4_10);
  tcase_add_test(tc, test_tetration_2_5_10);
  tcase_add_test(tc, test_tetration_3_4_10);
  tcase_add_test(tc, test_tetration_4_3_10);
  tcase_add_test(tc, test_tetration_4_3_2);
  tcase_add_test(tc, test_tetration_5_3_10);
  tcase_add_test(tc, test_tetration_5_3_2);
  tcase_add_test(tc, test_tetration_6_3_10);
  tcase_add_test(tc, test_tetration_6_3_2);
  suite_add_tcase(s, tc);
  return s;
}

Suite *create_matrix_ops_suite(void) {
  Suite *s = suite_create("Matrix Ops (2x2)");
  TCase *tc = tcase_create("Matrix_Ops");
  tcase_add_test(tc, test_mult_matrix_mod_1110_10);
  tcase_add_test(tc, test_mult_matrix_mod_2111_10);
  tcase_add_test(tc, test_pow_matrix_mod_1110_5_100);
  tcase_add_test(tc, test_pow_matrix_mod_1110_2_10);
  tcase_add_test(tc, test_pow_matrix_mod_1110_20_10);
  tcase_add_test(tc, test_pow_matrix_mod_1110_20000_64);
  tcase_add_test(tc, test_pow_matrix_mod_1230_20000_64);
  tcase_add_test(tc, test_pow_matrix_mod_1110_21_13);
  tcase_add_test(tc, test_pow_matrix_mod_1101_21_13);
  tcase_add_test(tc, test_pow_matrix_mod_1011_21_13);
  tcase_add_test(tc, test_pow_matrix_mod_0111_21_13);
  tcase_add_test(tc, test_pow_matrix_mod_1234_20000000_10);
  suite_add_tcase(s, tc);
  return s;
}

Suite *create_peasant_mult_suite(void) {
  Suite *s = suite_create("Peasant Mult (safe)");
  TCase *tc = tcase_create("Peasant_Mult");
  tcase_add_test(tc, test_mult_peasant_large);
  tcase_add_test(tc, test_mult_peasant_123_456_100);
  tcase_add_test(tc, test_mult_peasant_0_123_7);
  tcase_add_test(tc, test_mult_peasant_1_1_2);
  tcase_add_test(tc, test_mult_peasant_max_1000000000);
  suite_add_tcase(s, tc);
  return s;
}

int run_suite(Suite *s) {
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  int fails = srunner_ntests_failed(sr);
  srunner_free(sr);
  return fails;
}

int main(void) {
  int total_fails = 0;

  printf("\n--- Num To Fibo Mask ---\n");
  total_fails += run_suite(create_num_to_fibo_suite());

  printf("\n--- Game Logic ---\n");
  total_fails += run_suite(create_game_logic_suite());

  printf("\n--- Fast Fibonacci ---\n");
  total_fails += run_suite(create_fast_fibo_suite());

  printf("\n--- Pisano Period ---\n");
  total_fails += run_suite(create_pisano_suite());

  printf("\n--- Tetration ---\n");
  total_fails += run_suite(create_tetration_suite());

  printf("\n--- Matrix Operations ---\n");
  total_fails += run_suite(create_matrix_ops_suite());

  printf("\n--- Peasant Multiplication ---\n");
  total_fails += run_suite(create_peasant_mult_suite());

  if (total_fails > 0) {
    printf("\n❌ FAILED: %d tests failed in total.\n", total_fails);
  } else {
    printf("\n✅ SUCCESS: All tests passed!\n");
  }

  return (total_fails == 0) ? 0 : 1;
}