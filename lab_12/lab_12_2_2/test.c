#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "lib.h"

#define EQUAL     1
#define NOT_EQUAL 0

START_TEST(test_fib_ok)
{
    int arr[] = {0, 0, 0, 0, 0, 0, 0};

    fibonacci_arr_fill(arr, 7);

    ck_assert_int_eq(arr[6], 8);
}
END_TEST


Suite* fib_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("fib");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_fib_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_unique_ok)
{
    int arr[] = {1, 2, 3, 4, 5, 4, 2, 1};
    int arr_res[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int res_n = get_unique_arr(arr, 8, arr_res, 0);

    get_unique_arr(arr, 8, arr_res, res_n);

    for (int i = 0; i < 5; i++)
        ck_assert_int_eq(arr_res[i], i + 1);

}
END_TEST


Suite* unique_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("key");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_unique_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s_fib, *s_unique;
    SRunner *runner_fib, *runner_unique;

    s_fib = fib_suite();
    runner_fib = srunner_create(s_fib);

    s_unique = unique_suite();
    runner_unique = srunner_create(s_unique);

    srunner_run_all(runner_fib, CK_VERBOSE);
    srunner_run_all(runner_unique, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner_fib);
    no_failed += srunner_ntests_failed(runner_unique);

    srunner_free(runner_fib);
    srunner_free(runner_unique);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

