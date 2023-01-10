#include <check.h>
#include <stdio.h>

#include "snprintf.h"
#include "check_snprintf.h"

START_TEST(test_d_ok)
{
    char buff_1[100], buff_2[100];
    int n_1 = 23, n_2 = 23;

    int res_1 = my_snprintf(buff_1, n_1, "Giant horse №%d won", -92123);
    int res_2 = snprintf(buff_2, n_2, "Giant horse №%d won", -92123);

    ck_assert_int_eq(res_1, res_2);
    ck_assert_str_eq(buff_1, buff_2);
}
END_TEST

START_TEST(test_hd_ok)
{
    char buff_1[100], buff_2[100];
    int n_1 = 16, n_2 = 16;

    int res_1 = my_snprintf(buff_1, n_1, "Micro horse №%hd won", (short int) 12);
    int res_2 = snprintf(buff_2, n_2, "Micro horse №%hd won", (short int) 12);

    ck_assert_int_eq(res_1, res_2);
    ck_assert_str_eq(buff_1, buff_2);
}
END_TEST

START_TEST(test_i_ok)
{
    char buff_1[100], buff_2[100];
    int n_1 = 21, n_2 = 21;

    int res_1 = my_snprintf(buff_1, n_1, "Giant horse №%i won", 92123);
    int res_2 = snprintf(buff_2, n_2, "Giant horse №%i won", 92123);

    ck_assert_int_eq(res_1, res_2);
    ck_assert_str_eq(buff_1, buff_2);
}
END_TEST

START_TEST(test_hi_ok)
{
    char buff_1[100], buff_2[100];
    int n_1 = 18, n_2 = 18;

    int res_1 = my_snprintf(buff_1, n_1, "Micro horse №%hi won", (short int) -12);
    int res_2 = snprintf(buff_2, n_2, "Micro horse №%hi won", (short int) -12);

    ck_assert_int_eq(res_1, res_2);
    ck_assert_str_eq(buff_1, buff_2);
}
END_TEST

START_TEST(test_c_ok)
{
    char buff_1[100], buff_2[100];
    int n_1 = 12, n_2 = 12;

    int res_1 = my_snprintf(buff_1, n_1, "my fav letter is %c tbh", 'd');
    int res_2 = snprintf(buff_2, n_2, "my fav letter is %c tbh", 'd');

    ck_assert_int_eq(res_1, res_2);
    ck_assert_str_eq(buff_1, buff_2);
}
END_TEST

START_TEST(test_s_ok)
{
    char buff_1[100], buff_2[100];
    int n_1 = 12, n_2 = 12;

    int res_1 = my_snprintf(buff_1, n_1, "my fav word is %s tbh", "chapa");
    int res_2 = snprintf(buff_2, n_2, "my fav word is %s tbh", "chapa");

    ck_assert_int_eq(res_1, res_2);
    ck_assert_str_eq(buff_1, buff_2);
}
END_TEST

START_TEST(test_x_ok)
{
    char buff_1[100], buff_2[100];
    int n_1 = 12, n_2 = 12;

    int res_1 = my_snprintf(buff_1, n_1, "eeeh %x was lit", 1988);
    int res_2 = snprintf(buff_2, n_2, "eeeh %x was lit", 1988);

    ck_assert_int_eq(res_1, res_2);
    ck_assert_str_eq(buff_1, buff_2);
}
END_TEST

Suite* check_my_snprintf(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("snprintf tests");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_d_ok);
    tcase_add_test(tc_pos, test_hd_ok);
    tcase_add_test(tc_pos, test_i_ok);
    tcase_add_test(tc_pos, test_hi_ok);
    tcase_add_test(tc_pos, test_c_ok);
    tcase_add_test(tc_pos, test_s_ok);
    tcase_add_test(tc_pos, test_x_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}

