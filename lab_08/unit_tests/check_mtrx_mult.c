#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "mtrx_multiply.h"
#include "mem_operations.h"
#include "check_mtrx_mult.h"

START_TEST(test_mtrx_mult_1_1_ok)
{
   int n = 3, da = 1, db = 1;
   int64_t tmp_mtrx_2[3][3] = {{7, 1, 7}, {1, 7, 7}, {4, 4, 4}};
   int64_t tmp_mtrx_1[3][3] = {{1, 2, 3}, {3, 5, 6}, {1, 3, 4}};
   int64_t **mtrx_a = allocate_matrix(n, n);
   int64_t **mtrx_b = allocate_matrix(n, n);
   int64_t **mtrx_mult_res = NULL;

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {

         mtrx_a[i][j] = tmp_mtrx_1[i][j];
         mtrx_b[i][j] = tmp_mtrx_2[i][j];
      }

   int64_t res_mtrx[3][3] = {{21, 27, 33}, {50, 62, 80}, {26, 38, 44}};

   multiplied_mtrx_output(n, &mtrx_a, da, &mtrx_b, db, &mtrx_mult_res);

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         ck_assert_int_eq(mtrx_mult_res[i][j], res_mtrx[i][j]);

   free_matrix(mtrx_a, n);
   free_matrix(mtrx_b, n);
   free_matrix(mtrx_mult_res, n);
}
END_TEST

START_TEST(test_mtrx_mult_0_0_ok)
{
   int n = 3, da = 0, db = 0;
   int64_t tmp_mtrx_2[3][3] = {{7, 1, 7}, {1, 7, 7}, {4, 4, 4}};
   int64_t tmp_mtrx_1[3][3] = {{1, 2, 3}, {3, 5, 6}, {1, 3, 4}};
   int64_t **mtrx_a = allocate_matrix(n, n);
   int64_t **mtrx_b = allocate_matrix(n, n);
   int64_t **mtrx_mult_res = NULL;

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {

         mtrx_a[i][j] = tmp_mtrx_1[i][j];
         mtrx_b[i][j] = tmp_mtrx_2[i][j];
      }

   int64_t res_mtrx[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

   multiplied_mtrx_output(n, &mtrx_a, da, &mtrx_b, db, &mtrx_mult_res);

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         ck_assert_int_eq(mtrx_mult_res[i][j], res_mtrx[i][j]);

   free_matrix(mtrx_a, n);
   free_matrix(mtrx_b, n);
   free_matrix(mtrx_mult_res, n);
}
END_TEST

START_TEST(test_mtrx_mult_2_2_ok)
{
   int n = 3, da = 2, db = 2;
   int64_t tmp_mtrx_2[3][3] = {{7, 1, 7}, {1, 7, 7}, {4, 4, 4}};
   int64_t tmp_mtrx_1[3][3] = {{1, 2, 3}, {3, 5, 6}, {1, 3, 4}};
   int64_t **mtrx_a = allocate_matrix(n, n);
   int64_t **mtrx_b = allocate_matrix(n, n);
   int64_t **mtrx_mult_res = NULL;

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {

         mtrx_a[i][j] = tmp_mtrx_1[i][j];
         mtrx_b[i][j] = tmp_mtrx_2[i][j];
      }

   int64_t res_mtrx[3][3] = {{2958, 3354, 4548}, {6954, 7854, 10668}, {4086, 4626, 6276}};

   multiplied_mtrx_output(n, &mtrx_a, da, &mtrx_b, db, &mtrx_mult_res);

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         ck_assert_int_eq(mtrx_mult_res[i][j], res_mtrx[i][j]);

   free_matrix(mtrx_a, n);
   free_matrix(mtrx_b, n);
   free_matrix(mtrx_mult_res, n);
}
END_TEST

START_TEST(test_mtrx_mult_0_1_ok)
{
   int n = 3, da = 0, db = 1;
   int64_t tmp_mtrx_2[3][3] = {{7, 1, 7}, {1, 7, 7}, {4, 4, 4}};
   int64_t tmp_mtrx_1[3][3] = {{1, 2, 3}, {3, 5, 6}, {1, 3, 4}};
   int64_t **mtrx_a = allocate_matrix(n, n);
   int64_t **mtrx_b = allocate_matrix(n, n);
   int64_t **mtrx_mult_res = NULL;

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {

         mtrx_a[i][j] = tmp_mtrx_1[i][j];
         mtrx_b[i][j] = tmp_mtrx_2[i][j];
      }

   int64_t res_mtrx[3][3] = {{7, 1, 7}, {1, 7, 7}, {4, 4, 4}};

   multiplied_mtrx_output(n, &mtrx_a, da, &mtrx_b, db, &mtrx_mult_res);

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         ck_assert_int_eq(mtrx_mult_res[i][j], res_mtrx[i][j]);

   free_matrix(mtrx_a, n);
   free_matrix(mtrx_b, n);
   free_matrix(mtrx_mult_res, n);
}
END_TEST

Suite* mtrx_mult(void)
{
   Suite *s;
   TCase *tc_pos;

   s = suite_create("mtrx_multiply");

   tc_pos = tcase_create("positives");
   tcase_add_test(tc_pos, test_mtrx_mult_1_1_ok);
   tcase_add_test(tc_pos, test_mtrx_mult_0_0_ok);
   tcase_add_test(tc_pos, test_mtrx_mult_0_1_ok);
   tcase_add_test(tc_pos, test_mtrx_mult_2_2_ok);

   suite_add_tcase(s, tc_pos);

   return s;
}

