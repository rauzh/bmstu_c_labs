#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "node_funcs.h"
#include "defs.h"
#include "types.h"
#include "read_print.h"

START_TEST(test_find_ok)
{
    data_t d_1 = {1, "biba"};
    data_t d_2 = {2, "boba"};
    data_t d_3 = {0, "keke"};
    data_t d_4 = {7, "okok"};

    node_t n_4 = {&d_4, NULL};
    node_t n_3 = {&d_3, &n_4};
    node_t n_2 = {&d_2, &n_3};
    node_t n_1 = {&d_1, &n_2};

    node_t *head = &n_1;
    data_t element = {2, "boba"};

    node_t *found_element = find(head, &element, comparator_name);

    ck_assert_ptr_eq(found_element, &n_2);
}
END_TEST

START_TEST(test_find_neg)
{
    data_t d_1 = {1, "biba"};
    data_t d_2 = {2, "boba"};
    data_t d_3 = {0, "keke"};
    data_t d_4 = {7, "okok"};

    node_t n_4 = {&d_4, NULL};
    node_t n_3 = {&d_3, &n_4};
    node_t n_2 = {&d_2, &n_3};
    node_t n_1 = {&d_1, &n_2};

    node_t *head = &n_1;
    data_t element = {2, "heuheuheuehueheuheuehueh"};

    node_t *found_element = find(head, &element, comparator_name);

    ck_assert_ptr_eq(found_element, NULL);
}
END_TEST

Suite* check_find(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("check find");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_find_ok);

    suite_add_tcase(s, tc_pos);

    tc_pos = tcase_create("negatives");
    tcase_add_test(tc_pos, test_find_neg);

    suite_add_tcase(s, tc_pos);

    return s;
}
