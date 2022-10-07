#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "mtrx_operations.h"
#include "mem_operations.h"
#include "check_del_to_square.h"

START_TEST(test_del_columns)
{
   int n = 3, m = 4;
   int64_t tmp_mtrx[3][4] = {{1, 9, 2, 3}, {3, 4, 5, 6}, {1, 2, 3, 4}};
   int64_t **mtrx = allocate_matrix(n, m);

   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         mtrx[i][j] = tmp_mtrx[i][j];

   int64_t res_mtrx[3][3] = {{1, 2, 3}, {3, 5, 6}, {1, 3, 4}};

   del_columns(&n, &m, &mtrx);
   ck_assert_int_eq(n, 3);
   ck_assert_int_eq(m, 3);

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         ck_assert_int_eq(mtrx[i][j], res_mtrx[i][j]);

   free_matrix(mtrx, n);
}
END_TEST

START_TEST(test_del_rows)
{
   int m = 3, n = 4;
   int64_t tmp_mtrx[4][3] = {{1, 3, 1}, {9, 4, 2}, {2, 5, 3}, {3, 6, 3}};
   int64_t **mtrx = allocate_matrix(n, m);

   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         mtrx[i][j] = tmp_mtrx[i][j];

   int64_t res_mtrx[3][3] = {{1, 3, 1}, {2, 5, 3}, {3, 6, 3}};

   del_rows(&n, &m, &mtrx);
   ck_assert_int_eq(n, 3);
   ck_assert_int_eq(m, 3);

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         ck_assert_int_eq(mtrx[i][j], res_mtrx[i][j]);

   free_matrix(mtrx, n);
}
END_TEST

Suite* mtrx_del_to_sqr(void)
{
   Suite *s;
   TCase *tc_pos;

   s = suite_create("del_to_square");

   tc_pos = tcase_create("positives");
   tcase_add_test(tc_pos, test_del_columns);
   tcase_add_test(tc_pos, test_del_rows);

   suite_add_tcase(s, tc_pos);

   return s;
}

