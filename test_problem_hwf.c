#include <check.h>
#include <stdio.h>

int next_turn(int total, int possible);

START_TEST(test_next_turn_11_4) {
    ck_assert_int_eq(next_turn(11,4), 3);
}
END_TEST

START_TEST(test_next_turn_8_5) {
    ck_assert_int_eq(next_turn(8,5), 1);
}
END_TEST

START_TEST(test_next_turn_5_3) {
    ck_assert_int_eq(next_turn(5,3), 1);
}
END_TEST

START_TEST(test_next_turn_10_9) {
    ck_assert_int_eq(next_turn(10,9), 2);
}
END_TEST

START_TEST(test_next_turn_100_99) {
    ck_assert_int_eq(next_turn(100,99), 3);
}
END_TEST

START_TEST(test_next_turn_1000_999) {
    ck_assert_int_eq(next_turn(1000,999), 13);
}
END_TEST

START_TEST(test_next_turn_10000_9) {
    ck_assert_int_eq(next_turn(10000,9), 2);
}
END_TEST

START_TEST(test_next_turn_100000_8) {
    ck_assert_int_eq(next_turn(100000,8), 1);
}
END_TEST

START_TEST(test_next_turn_1000000_1000) {
    ck_assert_int_eq(next_turn(1000000,1000), 55);
}
END_TEST

START_TEST(test_next_turn_500500501_111) {
    ck_assert_int_eq(next_turn(500500501,111), 89);
}
END_TEST

START_TEST(test_next_turn_500500501_11) {
    ck_assert_int_eq(next_turn(500500501,11), 1);
}
END_TEST

START_TEST(test_next_turn_4_3) {
    ck_assert_int_eq(next_turn(4,3), 1);
}
END_TEST

Suite *pp_suite(void) {
    Suite *s = suite_create("problem_pp");
    TCase *tc_core = tcase_create("core");

    tcase_add_test(tc_core, test_next_turn_11_4);
    tcase_add_test(tc_core, test_next_turn_8_5);
    tcase_add_test(tc_core, test_next_turn_5_3);
    tcase_add_test(tc_core, test_next_turn_10_9);
    tcase_add_test(tc_core, test_next_turn_100_99);
    tcase_add_test(tc_core, test_next_turn_1000_999);
    tcase_add_test(tc_core, test_next_turn_10000_9);
    tcase_add_test(tc_core, test_next_turn_100000_8);
    tcase_add_test(tc_core, test_next_turn_1000000_1000);
    tcase_add_test(tc_core, test_next_turn_500500501_111);
    tcase_add_test(tc_core, test_next_turn_500500501_11);
    tcase_add_test(tc_core, test_next_turn_4_3);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void) {
    Suite *s = pp_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    int fails = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (fails == 0) ? 0 : 1;
}
