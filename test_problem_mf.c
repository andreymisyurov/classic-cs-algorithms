#include <check.h>
#include <stdio.h>

struct Matrix {
    unsigned a00, a01;
    unsigned a10, a11;
};

struct Matrix mult_mtrx_mod(const struct Matrix mtrx1, const struct Matrix mtrx2, unsigned m);
struct Matrix pow_mtrx(struct Matrix mtrx, int64_t n, unsigned m);

START_TEST(test_mult_mtrx_mod_1110_10) {
    struct Matrix mtrx = {1,1,1,0};
    mtrx = mult_mtrx_mod(mtrx, mtrx, 10);
    ck_assert_int_eq(mtrx.a00, 2);
    ck_assert_int_eq(mtrx.a01, 1);
    ck_assert_int_eq(mtrx.a10, 1);
    ck_assert_int_eq(mtrx.a11, 1);
}
END_TEST

START_TEST(test_mult_mtrx_mod_2111_10) {
    struct Matrix mtrx = {2,1,1,1};
    mtrx = mult_mtrx_mod(mtrx, mtrx, 10);
    ck_assert_int_eq(mtrx.a00, 5);
    ck_assert_int_eq(mtrx.a01, 3);
    ck_assert_int_eq(mtrx.a10, 3);
    ck_assert_int_eq(mtrx.a11, 2);
}
END_TEST

START_TEST(test_pow_mtrx_1110_5_100) {
    struct Matrix mtrx = {1,1,1,0};
    mtrx = pow_mtrx(mtrx, 5, 100);
    ck_assert_int_eq(mtrx.a00, 8);
    ck_assert_int_eq(mtrx.a01, 5);
    ck_assert_int_eq(mtrx.a10, 5);
    ck_assert_int_eq(mtrx.a11, 3);
}
END_TEST

START_TEST(test_pow_mtrx_1110_2_100) {
    struct Matrix mtrx = {1,1,1,0};
    mtrx = pow_mtrx(mtrx, 2, 10);
    ck_assert_int_eq(mtrx.a00, 2);
    ck_assert_int_eq(mtrx.a01, 1);
    ck_assert_int_eq(mtrx.a10, 1);
    ck_assert_int_eq(mtrx.a11, 1);
}
END_TEST

START_TEST(test_pow_mtrx_1110_20_10) {
    struct Matrix mtrx = {1,1,1,0};
    mtrx = pow_mtrx(mtrx, 20, 10);
    ck_assert_int_eq(mtrx.a00, 6);
    ck_assert_int_eq(mtrx.a01, 5);
    ck_assert_int_eq(mtrx.a10, 5);
    ck_assert_int_eq(mtrx.a11, 1);
}
END_TEST

START_TEST(test_pow_mtrx_1110_20000_64) {
    struct Matrix mtrx = {1,1,1,0};
    mtrx = pow_mtrx(mtrx, 20000, 64);
    ck_assert_int_eq(mtrx.a00, 34);
    ck_assert_int_eq(mtrx.a01, 5);
    ck_assert_int_eq(mtrx.a10, 5);
    ck_assert_int_eq(mtrx.a11, 29);
}
END_TEST


START_TEST(test_pow_mtrx_1230_20000_64) {
    struct Matrix mtrx = {1,2,3,0};
    mtrx = pow_mtrx(mtrx, 20000, 64);
    ck_assert_int_eq(mtrx.a00, 39);
    ck_assert_int_eq(mtrx.a01, 26);
    ck_assert_int_eq(mtrx.a10, 39);
    ck_assert_int_eq(mtrx.a11, 26);
}
END_TEST

START_TEST(test_pow_mtrx_1110_21_13) {
    struct Matrix mtrx = {1,1,1,0};
    mtrx = pow_mtrx(mtrx, 21, 13);
    ck_assert_int_eq(mtrx.a00, 5);
    ck_assert_int_eq(mtrx.a01, 0);
    ck_assert_int_eq(mtrx.a10, 0);
    ck_assert_int_eq(mtrx.a11, 5);
}
END_TEST

START_TEST(test_pow_mtrx_1101_21_13) {
    struct Matrix mtrx = {1,1,0,1};
    mtrx = pow_mtrx(mtrx, 21, 13);
    ck_assert_int_eq(mtrx.a00, 1);
    ck_assert_int_eq(mtrx.a01, 8);
    ck_assert_int_eq(mtrx.a10, 0);
    ck_assert_int_eq(mtrx.a11, 1);
}
END_TEST

START_TEST(test_pow_mtrx_1011_21_13) {
    struct Matrix mtrx = {1,0,1,1};
    mtrx = pow_mtrx(mtrx, 21, 13);
    ck_assert_int_eq(mtrx.a00, 1);
    ck_assert_int_eq(mtrx.a01, 0);
    ck_assert_int_eq(mtrx.a10, 8);
    ck_assert_int_eq(mtrx.a11, 1);
}
END_TEST

START_TEST(test_pow_mtrx_0111_21_13) {
    struct Matrix mtrx = {0,1,1,1};
    mtrx = pow_mtrx(mtrx, 21, 13);
    ck_assert_int_eq(mtrx.a00, 5);
    ck_assert_int_eq(mtrx.a01, 0);
    ck_assert_int_eq(mtrx.a10, 0);
    ck_assert_int_eq(mtrx.a11, 5);
}
END_TEST

START_TEST(test_pow_mtrx_1234_20000000_10) {
    struct Matrix mtrx = {1,2,3,4};
    mtrx = pow_mtrx(mtrx, 20000000, 10);
    ck_assert_int_eq(mtrx.a00, 1);
    ck_assert_int_eq(mtrx.a01, 0);
    ck_assert_int_eq(mtrx.a10, 5);
    ck_assert_int_eq(mtrx.a11, 6);
}
END_TEST

Suite *pp_suite(void) {
    Suite *s = suite_create("problem_pp");
    TCase *tc_core = tcase_create("core");

    tcase_add_test(tc_core, test_pow_mtrx_1110_20_10);
    tcase_add_test(tc_core, test_pow_mtrx_1110_20000_64);
    tcase_add_test(tc_core, test_pow_mtrx_1230_20000_64);
    tcase_add_test(tc_core, test_pow_mtrx_1110_21_13);
    tcase_add_test(tc_core, test_pow_mtrx_1101_21_13);
    tcase_add_test(tc_core, test_pow_mtrx_1011_21_13);
    tcase_add_test(tc_core, test_pow_mtrx_0111_21_13);
    tcase_add_test(tc_core, test_pow_mtrx_1234_20000000_10);
    tcase_add_test(tc_core, test_mult_mtrx_mod_1110_10);
    tcase_add_test(tc_core, test_mult_mtrx_mod_2111_10);
    tcase_add_test(tc_core, test_pow_mtrx_1110_5_100);
    tcase_add_test(tc_core, test_pow_mtrx_1110_2_100);

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
