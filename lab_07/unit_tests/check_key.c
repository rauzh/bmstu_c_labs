#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "filter.h"
#include "check_key.h"
#include "defs.h"

START_TEST(test_key_ok)
        {
                int arr[] = {1, 2, 3, 4, 5, 6};
                int arr_res[] = {4, 5, 6};
                int *arr_dst = NULL, *arr_dst_end = NULL;

                ck_assert_int_eq(key(arr, arr + 6, &arr_dst, &arr_dst_end), EXIT_SUCCESS);
                ck_assert_int_eq(arr_dst_end - arr_dst, 3);

                for (size_t i = 0; i < 3; i++)
                    ck_assert_int_eq(arr_dst[i], arr_res[i]);

                free(arr_dst);
        }
END_TEST

START_TEST(test_key_invalid_params)
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int *arr_dst = NULL, *arr_dst_end = NULL;

    ck_assert_int_eq(key(arr + 4, arr + 2, &arr_dst, &arr_dst_end), INVALID_PARAMETERS);

    free(arr_dst);
}
END_TEST


Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("key");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_ok);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_key_invalid_params);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}

