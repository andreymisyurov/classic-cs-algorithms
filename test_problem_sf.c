#include <check.h>
#include <stdio.h>

unsigned long long sum_fibo(unsigned long long);

START_TEST(test_sum_fibo_1) {
    ck_assert_int_eq(sum_fibo(1), 1); // 1 == 0b0001
}
END_TEST

START_TEST(test_sum_fibo_4) {
    ck_assert_int_eq(sum_fibo(4), 5); // 5 == 0b0101
}
END_TEST

START_TEST(test_sum_fibo_11) {
    ck_assert_int_eq(sum_fibo(11), 20); // 20 == 0b00010100
}
END_TEST

START_TEST(test_sum_fibo_20) {
    ck_assert_int_eq(sum_fibo(20), 42); // 42 == 0b00101010
}
END_TEST

START_TEST(test_sum_fibo_123456) {
    ck_assert_int_eq(sum_fibo(123456), 16814592); // 16814592 == 1000000001001001000000000
}
END_TEST

START_TEST(test_sum_fibo_654321) {
    ck_assert_int_eq(sum_fibo(654321), 152059905); // 152059905 == 1000000001001001000000000
}
END_TEST

START_TEST(test_sum_fibo_101010101) {
    ck_assert_int_eq(sum_fibo(101010101), 182805727745); // 182805727745 == 10101010010000000100100000101000000001
}
END_TEST

START_TEST(test_sum_fibo_202020202) {
    ck_assert_int_eq(sum_fibo(202020202), 594050424962); // 594050424962 == 1000101001010000001010100010000010000010
}
END_TEST

START_TEST(test_sum_fibo_1234567890) {
    ck_assert_int_eq(sum_fibo(1234567890), 8977825023301); // 8977825023301 == 10000010101001010000000100100100010101000101
}
END_TEST

START_TEST(test_sum_fibo_1000000000) {
    ck_assert_int_eq(sum_fibo(1000000000), 5536391137833); // 5536391137833 == 1010000100100001010101000001000101000101001
}
END_TEST

Suite *pp_suite(void) {
    Suite *s = suite_create("problem_sf");
    TCase *tc_core = tcase_create("core");

    tcase_add_test(tc_core, test_sum_fibo_4);
    tcase_add_test(tc_core, test_sum_fibo_1);
    tcase_add_test(tc_core, test_sum_fibo_11);
    tcase_add_test(tc_core, test_sum_fibo_20);
    tcase_add_test(tc_core, test_sum_fibo_123456);
    tcase_add_test(tc_core, test_sum_fibo_654321);
    tcase_add_test(tc_core, test_sum_fibo_101010101);
    tcase_add_test(tc_core, test_sum_fibo_202020202);
    tcase_add_test(tc_core, test_sum_fibo_1234567890);
    tcase_add_test(tc_core, test_sum_fibo_1000000000);

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
