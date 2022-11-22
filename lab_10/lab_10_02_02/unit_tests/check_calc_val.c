#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "calculate_funcs.h"
#include "node_funcs.h"
#include "check_calc_val.h"
#include "defs.h"
#include "types.h"
#include "read_print.h"

START_TEST(test_calc_val_ok)
{
    node_t *pol, *tmp = NULL;
    pol = tmp;

    tmp = node_create(4);
    add_to_tail(&pol, tmp);
    tmp = node_create(2);
    add_to_tail(&pol, tmp);
    tmp = node_create(0);
    add_to_tail(&pol,tmp);
    tmp = node_create(6);
    add_to_tail(&pol, tmp);

    int res = 0;
    polynom_print(pol);
    int expected_res = 556;
    calculate_value(pol, 5, &res);
    free_list(pol);

    ck_assert_int_eq(res, expected_res);
}
END_TEST


Suite* calc_val(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("calc val");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_calc_val_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}
