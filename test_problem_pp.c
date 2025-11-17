#include <check.h>
#include <stdio.h>

long long fibo(long longn, long longmod, long long*pizo);

// fib(0) mod 10 = 0
START_TEST(test_fibo_0_mod_10) {
    long long pizo = 0;
    ck_assert_int_eq(fibo(0, 10, &pizo), 0);
    ck_assert_int_eq(pizo, 60);
}
END_TEST

// fib(1) mod 10 = 0
START_TEST(test_fibo_1_mod_10) {
    long long pizo = 0;
    ck_assert_int_eq(fibo(1, 10, &pizo), 1);
    ck_assert_int_eq(pizo, 60);
}
END_TEST

// fib(10) mod 10 = 5
START_TEST(test_fibo_10_mod_10) {
    long long pizo = 0;
    ck_assert_int_eq(fibo(10, 10, &pizo), 5);
    ck_assert_int_eq(pizo, 60);
}
END_TEST

// fib(9000) mod 120 = 0
START_TEST(test_fibo_9000_mod_120) {
    long long pizo = 0;
    ck_assert_int_eq(fibo(9000, 120, &pizo), 0);
    ck_assert_int_eq(pizo, 120);
}
END_TEST

// fib(121000) mod 1300 = 1275
START_TEST(test_fibo_121000_mod_1300) {
    long long pizo = 0;
    ck_assert_int_eq(fibo(121000, 1300, &pizo), 1275);
    ck_assert_int_eq(pizo, 2100);
}
END_TEST

 
// fib(183111111) mod 152222 = 1275
START_TEST(test_fibo_183111111_mod_152222) {
    long long pizo = 0;
    ck_assert_int_eq(fibo(183111111, 152222, &pizo), 71658);
    ck_assert_int_eq(pizo, 21840);
}
END_TEST

// fib(21433333333) mod 167890 = 1275
START_TEST(test_fibo_21433333333_mod_167890) {
    long long pizo = 0;
    ck_assert_int_eq(fibo(21433333333, 167890, &pizo), 128323);
    ck_assert_int_eq(pizo, 127920);
}
END_TEST

// fib(500500500500500) mod 1111111 = 1275
START_TEST(test_fibo_500500500500500_mod_1111111) {
    long long pizo = 0;
    ck_assert_int_eq(fibo(500500500500500, 1111111, &pizo), 912200);
    ck_assert_int_eq(pizo, 19754);
}
END_TEST

Suite *pp_suite(void) {
    Suite *s = suite_create("problem_pp");
    TCase *tc_core = tcase_create("core");

    tcase_add_test(tc_core, test_fibo_0_mod_10);
    tcase_add_test(tc_core, test_fibo_1_mod_10);
    tcase_add_test(tc_core, test_fibo_9000_mod_120);
    tcase_add_test(tc_core, test_fibo_121000_mod_1300);
    tcase_add_test(tc_core, test_fibo_10_mod_10);
    tcase_add_test(tc_core, test_fibo_183111111_mod_152222);
    tcase_add_test(tc_core, test_fibo_21433333333_mod_167890);
    tcase_add_test(tc_core, test_fibo_500500500500500_mod_1111111);

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
