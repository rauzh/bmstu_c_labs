#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "check_arr_mean.h"
#include "filter.h"
#include "check_mysort.h"
#include "check_key.h"

int main(void)
{
    int no_failed = 0;
    Suite *s_mean, *s_key, *s_sort;
    SRunner *runner_mean, *runner_key, *runner_sort;

    s_mean = arr_mean_suite();
    runner_mean = srunner_create(s_mean);

    s_key = key_suite();
    runner_key = srunner_create(s_key);

    s_sort = mysort_suite();
    runner_sort = srunner_create(s_sort);

    srunner_run_all(runner_mean, CK_VERBOSE);
    srunner_run_all(runner_key, CK_VERBOSE);
    srunner_run_all(runner_sort, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner_mean);
    no_failed += srunner_ntests_failed(runner_key);
    no_failed += srunner_ntests_failed(runner_sort);

    srunner_free(runner_mean);
    srunner_free(runner_key);
    srunner_free(runner_sort);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
