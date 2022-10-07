#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "mtrx_operations.h"
#include "mem_operations.h"
#include "check_add_to_square.h"

START_TEST(test_add_to_square_ok)
{
   int n = 2, m = 2, z = 3;
   int64_t tmp_mtrx[2][2] = {{7, 1}, {1, 7}};
   int64_t **mtrx = allocate_matrix(n, m);

   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         mtrx[i][j] = tmp_mtrx[i][j];

   int64_t res_mtrx[3][3] = {{7, 1, 7}, {1, 7, 7}, {4, 4, 4}};

   add_rows(&n, &z, &mtrx);
   add_columns(&n, &z, &mtrx);

   for (int i = 0; i < z; i++)
      for (int j = 0; j < z; j++)
         ck_assert_int_eq(mtrx[i][j], res_mtrx[i][j]);

   free_matrix(mtrx, z);
}
END_TEST

Suite* mtrx_add_to_sqr(void)
{
   Suite *s;
   TCase *tc_pos;

   s = suite_create("add_to_square");

   tc_pos = tcase_create("positives");
   tcase_add_test(tc_pos, test_add_to_square_ok);

   suite_add_tcase(s, tc_pos);

   return s;
}

