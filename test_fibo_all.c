#include <check.h>
#include <stdio.h>

#include "fibo.h"

// TCase: Num_To_Fibo_Mask

// [num_to_fibo_mask] Val: 1 -> mask: 1 (0b1)
START_TEST(test_num_to_fibo_mask_1) {
    ck_assert_int_eq(num_to_fibo_mask(1), 1);
}
END_TEST

// [num_to_fibo_mask] Val: 4 -> mask: 5 (0b101)
START_TEST(test_num_to_fibo_mask_4) {
    ck_assert_int_eq(num_to_fibo_mask(4), 5);
}
END_TEST

// [num_to_fibo_mask] Val: 11 -> mask: 20 (0b10100)
START_TEST(test_num_to_fibo_mask_11) {
    ck_assert_int_eq(num_to_fibo_mask(11), 20);
}
END_TEST

// [num_to_fibo_mask] Val: 20 -> mask: 42 (0b101010)
START_TEST(test_num_to_fibo_mask_20) {
    ck_assert_int_eq(num_to_fibo_mask(20), 42);
}
END_TEST

// [num_to_fibo_mask] Val: 123456 -> mask: 16814592
START_TEST(test_num_to_fibo_mask_123456) {
    ck_assert_int_eq(num_to_fibo_mask(123456), 16814592);
}
END_TEST

// [num_to_fibo_mask] Val: 654321 -> mask: 152059905
START_TEST(test_num_to_fibo_mask_654321) {
    ck_assert_int_eq(num_to_fibo_mask(654321), 152059905);
}
END_TEST

// [num_to_fibo_mask] Val: 101010101 -> mask: 182805727745
START_TEST(test_num_to_fibo_mask_101010101) {
    ck_assert_int_eq(num_to_fibo_mask(101010101), 182805727745);
}
END_TEST

// [num_to_fibo_mask] Val: 202020202 -> mask: 594050424962
START_TEST(test_num_to_fibo_mask_202020202) {
    ck_assert_int_eq(num_to_fibo_mask(202020202), 594050424962);
}
END_TEST

// [num_to_fibo_mask] Val: 1234567890 -> mask: 8977825023301
START_TEST(test_num_to_fibo_mask_1234567890) {
    ck_assert_int_eq(num_to_fibo_mask(1234567890), 8977825023301);
}
END_TEST

// [num_to_fibo_mask] Val: 1000000000 -> mask: 5536391137833
START_TEST(test_num_to_fibo_mask_1000000000) {
    ck_assert_int_eq(num_to_fibo_mask(1000000000), 5536391137833);
}
END_TEST


// TCase: Game Logic

// [next_turn] Total: 11, Max: 4 -> 3
START_TEST(test_next_turn_11_4) {
    ck_assert_int_eq(next_turn(11,4), 3);
}
END_TEST

// [next_turn] Total: 8, Max: 5 -> 1
START_TEST(test_next_turn_8_5) {
    ck_assert_int_eq(next_turn(8,5), 1);
}
END_TEST

// [next_turn] Total: 5, Max: 3 -> 1
START_TEST(test_next_turn_5_3) {
    ck_assert_int_eq(next_turn(5,3), 1);
}
END_TEST

// [next_turn] Total: 10, Max: 9 -> 2
START_TEST(test_next_turn_10_9) {
    ck_assert_int_eq(next_turn(10,9), 2);
}
END_TEST

// [next_turn] Total: 100, Max: 99 -> 3
START_TEST(test_next_turn_100_99) {
    ck_assert_int_eq(next_turn(100,99), 3);
}
END_TEST

// [next_turn] Total: 1000, Max: 999 -> 13
START_TEST(test_next_turn_1000_999) {
    ck_assert_int_eq(next_turn(1000,999), 13);
}
END_TEST

// [next_turn] Total: 10000, Max: 9 -> 2
START_TEST(test_next_turn_10000_9) {
    ck_assert_int_eq(next_turn(10000,9), 2);
}
END_TEST

// [next_turn] Total: 100000, Max: 8 -> 1
START_TEST(test_next_turn_100000_8) {
    ck_assert_int_eq(next_turn(100000,8), 1);
}
END_TEST

// [next_turn] Total: 1000000, Max: 1000 -> 55
START_TEST(test_next_turn_1000000_1000) {
    ck_assert_int_eq(next_turn(1000000,1000), 55);
}
END_TEST

// [next_turn] Total: 500500501, Max: 111 -> 89
START_TEST(test_next_turn_500500501_111) {
    ck_assert_int_eq(next_turn(500500501,111), 89);
}
END_TEST

// [next_turn] Total: 500500501, Max: 11 -> 1
START_TEST(test_next_turn_500500501_11) {
    ck_assert_int_eq(next_turn(500500501,11), 1);
}
END_TEST

// [next_turn] Total: 4, Max: 3 -> 1
START_TEST(test_next_turn_4_3) {
    ck_assert_int_eq(next_turn(4,3), 1);
}
END_TEST


// TCase: Fast_Fibo

// [get_fibo_fast] N: 0, Mod: 10 -> 0
START_TEST(test_fibo_fast_0_10) {
    ck_assert_int_eq(get_fibo_fast(0, 10), 0);
}
END_TEST

// [get_fibo_fast] N: 90, Mod: 12 -> 4
START_TEST(test_fibo_fast_90_12) {
    ck_assert_int_eq(get_fibo_fast(90, 12), 4);
}
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

Suite *fibo_suite(void) {
    Suite *s = suite_create("Fibo_Unified");
    
    // TCase 1: Num_To_Fibo_Mask
    TCase *tc_sf = tcase_create("Num_To_Fibo_Mask");
    tcase_add_test(tc_sf, test_num_to_fibo_mask_4);
    tcase_add_test(tc_sf, test_num_to_fibo_mask_1);
    tcase_add_test(tc_sf, test_num_to_fibo_mask_11);
    tcase_add_test(tc_sf, test_num_to_fibo_mask_20);
    tcase_add_test(tc_sf, test_num_to_fibo_mask_123456);
    tcase_add_test(tc_sf, test_num_to_fibo_mask_654321);
    tcase_add_test(tc_sf, test_num_to_fibo_mask_101010101);
    tcase_add_test(tc_sf, test_num_to_fibo_mask_202020202);
    tcase_add_test(tc_sf, test_num_to_fibo_mask_1234567890);
    tcase_add_test(tc_sf, test_num_to_fibo_mask_1000000000);
    suite_add_tcase(s, tc_sf);

    // TCase 2: Game Logic
    TCase *tc_hwf = tcase_create("Game_Logic");
    tcase_add_test(tc_hwf, test_next_turn_11_4);
    tcase_add_test(tc_hwf, test_next_turn_8_5);
    tcase_add_test(tc_hwf, test_next_turn_5_3);
    tcase_add_test(tc_hwf, test_next_turn_10_9);
    tcase_add_test(tc_hwf, test_next_turn_100_99);
    tcase_add_test(tc_hwf, test_next_turn_1000_999);
    tcase_add_test(tc_hwf, test_next_turn_10000_9);
    tcase_add_test(tc_hwf, test_next_turn_100000_8);
    tcase_add_test(tc_hwf, test_next_turn_1000000_1000);
    tcase_add_test(tc_hwf, test_next_turn_500500501_111);
    tcase_add_test(tc_hwf, test_next_turn_500500501_11);
    tcase_add_test(tc_hwf, test_next_turn_4_3);
    suite_add_tcase(s, tc_hwf);

    // TCase 3: Fast Fibonacci
    TCase *tc_fm = tcase_create("Fast_Fibo");
    tcase_add_test(tc_fm, test_fibo_fast_0_10);
    tcase_add_test(tc_fm, test_fibo_fast_90_12);
    tcase_add_test(tc_fm, test_fibo_fast_121_13);
    tcase_add_test(tc_fm, test_fibo_fast_152_14);
    tcase_add_test(tc_fm, test_fibo_fast_183_15);
    tcase_add_test(tc_fm, test_fibo_fast_214_16);
    tcase_add_test(tc_fm, test_fibo_fast_245_17);
    tcase_add_test(tc_fm, test_fibo_fast_500_11);
    tcase_add_test(tc_fm, test_fibo_fast_1000_35);
    tcase_add_test(tc_fm, test_fibo_fast_2000_49);
    suite_add_tcase(s, tc_fm);

    return s;
}

int main(void) {
    Suite *s = fibo_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    int fails = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (fails == 0) ? 0 : 1;
}
