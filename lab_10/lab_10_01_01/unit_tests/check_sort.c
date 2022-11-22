#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "node_funcs.h"
#include "defs.h"
#include "types.h"
#include "read_print.h"

START_TEST(test_sort_ok)
{
    data_t d_1 = {0, "biba"};
    data_t d_2 = {1, "keke"};
    data_t d_3 = {2, "keke"};
    data_t d_4 = {3, "keke"};

    node_t n_4 = {&d_4, NULL};
    node_t n_3 = {&d_3, &n_4};
    node_t n_2 = {&d_2, &n_3};
    node_t n_1 = {&d_1, &n_2};

    node_t *head = &n_1;

    node_t *new_head = sort(head, comparator_type);

    ck_assert_ptr_eq(new_head, &n_4);

    for (int i = 3; new_head != NULL; new_head = new_head->next, i--)
    {
        data_t *tmp_data = new_head->data;
        ck_assert_int_eq(tmp_data->aim_type, i);
    }
}
END_TEST

Suite* check_sort(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("check sort");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}
