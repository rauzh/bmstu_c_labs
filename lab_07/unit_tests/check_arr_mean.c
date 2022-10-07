#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "filter.h"
#include "check_arr_mean.h"

#define EPS 1e-7

START_TEST(test_arr_mean_ok)
{
    float avg;
    int arr[] = {3, 3, 5, 5, 3, 3, 5, 5};

    avg = arr_mean(arr, arr + 8);
    ck_assert_double_lt(fabs(avg - 4.0), EPS);
}
END_TEST

START_TEST(test_arr_mean_ok_zero)
{
    float avg;
    int arr[] = {-1, 0, 1};

    avg = arr_mean(arr, arr + 3);
    ck_assert_double_lt(fabs(avg - 0.0), EPS);
}
END_TEST

Suite* arr_mean_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("arr_mean");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_arr_mean_ok);
    tcase_add_test(tc_pos, test_arr_mean_ok_zero);

    suite_add_tcase(s, tc_pos);

    return s;
}

