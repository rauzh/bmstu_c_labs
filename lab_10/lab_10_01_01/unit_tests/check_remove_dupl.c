#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "node_funcs.h"
#include "defs.h"
#include "types.h"
#include "read_print.h"

START_TEST(test_remove_dupl_ok)
{
    data_t d_1 = {0, "biba"};
    data_t d_2 = {1, "keke"};
    data_t d_3 = {2, "keke"};
    data_t d_4 = {2, "keke"};
// не проверяем правильность выделения памяти, так как это не относится к тесту.
    node_t *head = allocate_node();
    node_t *cur_node = head;
    cur_node->data = &d_1;

    node_t *new_node = allocate_node();
    cur_node->next = new_node;
    cur_node = new_node;
    cur_node->data = &d_2;

    new_node = allocate_node();
    cur_node->next = new_node;
    cur_node = new_node;
    cur_node->data = &d_3;

    new_node = allocate_node();
    cur_node->next = new_node;
    cur_node = new_node;
    cur_node->data = &d_4;

    node_t *res_head = head;

    remove_duplicates(&res_head, comparator_name);

    ck_assert_ptr_eq(res_head, head);

    node_t *cur_head = head;

    for (int i = 0; cur_head != NULL; cur_head = cur_head->next, i++)
    {
        data_t *tmp_data = cur_head->data;
        ck_assert_int_eq(tmp_data->aim_type, i);
    }

    while (head != NULL)
    {
        node_t *tmp_node = head->next;
        free(head);
        head = tmp_node;
    }
}
END_TEST

Suite* check_remove_dupl(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("check remove dupl");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_remove_dupl_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}
