#include <string.h>
#include <check.h>
#include <stdlib.h>

#include "mtrx_operations.h"
#include "mem_operations.h"
#include "check_avg.h"

START_TEST(test_avg_ok_pos)
{
   int64_t avg;
   int64_t tmp_mtrx[][3] = {{4, 4, 3}, {6, 9, 10}, {8, 2, 3}};
   int64_t **mtrx = allocate_matrix(3, 3);
   for (int i = 0; i < 3; i++)
   {
      free(mtrx[i]);
      mtrx[i] = tmp_mtrx[i];
   }

   avg = get_avg_of_column(3, 0, &mtrx);
   free(mtrx);
   ck_assert_int_eq(avg, 6);
}
END_TEST

START_TEST(test_avg_ok_neg)
{
   int64_t avg;
   int64_t tmp_mtrx[][3] = {{3, 4, -6}, {10, 9, 0}, {1, 2, -1}};
   int64_t **mtrx = allocate_matrix(3, 3);
   for (int i = 0; i < 3; i++)
   {
      free(mtrx[i]);
      mtrx[i] = tmp_mtrx[i];
   }

   avg = get_avg_of_column(3, 2, &mtrx);
   free(mtrx);
   ck_assert_int_eq(avg, -3);
}
END_TEST

Suite* mtrx_avg(void)
{
   Suite *s;
   TCase *tc_pos;

   s = suite_create("avg_of_column");

   tc_pos = tcase_create("positives");
   tcase_add_test(tc_pos, test_avg_ok_pos);
   tcase_add_test(tc_pos, test_avg_ok_neg);

   suite_add_tcase(s, tc_pos);

   return s;
}

