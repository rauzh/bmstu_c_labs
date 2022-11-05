#define _GNU_SOURCE

#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "sort_funcs.h"
#include "check_sort.h"
#include "defs.h"
#include "types.h"

#define ARR_LEN 3

START_TEST(test_sort_ok)
{
    items_t arr[ARR_LEN];
    items_t arr_res[ARR_LEN];

    arr[0].name = "a"; arr[0].weight = 10;     arr[0].volume = 10;
    arr[1].name = "b"; arr[1].weight = 200000; arr[1].volume = 4;
    arr[2].name = "c"; arr[2].weight = 1000;   arr[2].volume = 7.99;

    arr_res[0].name = "a"; arr_res[0].weight = 10;     arr_res[0].volume = 10;
    arr_res[1].name = "c"; arr_res[1].weight = 1000;   arr_res[1].volume = 7.99;
    arr_res[2].name = "b"; arr_res[2].weight = 200000; arr_res[2].volume = 4;

    sort_by_density(arr, 3);

    for (size_t i = 0; i < 3; i++)
        ck_assert_int_eq(strcmp(arr_res[i].name, arr[i].name), EQUAL);
}
END_TEST


Suite* arr_sort(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}
