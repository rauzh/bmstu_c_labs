#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "sort_funcs.h"
#include "check_mysort.h"
#include "defs.h"

START_TEST(test_mysort_ok)
        {
                int arr[] = {1, 2, 6, 4, 5, 3};
                int arr_res[] = {1, 2, 3, 4, 5, 6};

                mysort(arr, 6, sizeof(int), (int(*)(const void *, const void *)) compare);

                for (size_t i = 0; i < 6; i++)
                    ck_assert_int_eq(arr[i], arr_res[i]);
        }
END_TEST


Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mysort_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}