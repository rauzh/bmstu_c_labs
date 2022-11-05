#define _GNU_SOURCE

#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "read_print.h"
#include "check_specify.h"
#include "defs.h"
#include "types.h"

#define ARR_LEN 3

START_TEST(test_spec_neg)
{
    items_t arr[ARR_LEN];

    arr[0].name = "baaaba"; arr[0].weight = 10;     arr[0].volume = 10;
    arr[1].name = "skirtt"; arr[1].weight = 200000; arr[1].volume = 4;
    arr[2].name = "le_chappo"; arr[2].weight = 1000;   arr[2].volume = 7.99;

    int rc = print_specific_items("kok", arr, 3);

    ck_assert_int_eq(rc, NO_SPECIFIC_ITEM);
}
END_TEST

START_TEST(test_spec_ok)
{
    items_t arr[ARR_LEN];

    arr[0].name = "baaaba"; arr[0].weight = 10;     arr[0].volume = 10;
    arr[1].name = "le_bumbo"; arr[1].weight = 200000; arr[1].volume = 4;
    arr[2].name = "le_chappo"; arr[2].weight = 1000;   arr[2].volume = 7.99;

    int rc = print_specific_items("le", arr, 3);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST


Suite* arr_specify(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("specify");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_spec_ok);

    tc_neg = tcase_create("negaives");
    tcase_add_test(tc_pos, test_spec_neg);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);

    return s;
}
