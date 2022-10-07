#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "check_avg.h"
#include "check_del_to_square.h"
#include "check_add_to_square.h"
#include "check_mtrx_mult.h"

int main(void)
{
   int no_failed = 0;
   Suite *s_avg, *s_del, *s_add, *s_mult;
   SRunner *runner_avg, *runner_del, *runner_add, *runner_mult;

   s_avg = mtrx_avg();
   s_del = mtrx_del_to_sqr();
   s_add = mtrx_add_to_sqr();
   s_mult = mtrx_mult();

   runner_avg = srunner_create(s_avg);
   runner_del = srunner_create(s_del);
   runner_add = srunner_create(s_add);
   runner_mult = srunner_create(s_mult);

   srunner_run_all(runner_avg, CK_VERBOSE);
   srunner_run_all(runner_del, CK_VERBOSE);
   srunner_run_all(runner_add, CK_VERBOSE);
   srunner_run_all(runner_mult, CK_VERBOSE);

   no_failed = srunner_ntests_failed(runner_avg);
   no_failed += srunner_ntests_failed(runner_del);
   no_failed += srunner_ntests_failed(runner_add);
   no_failed += srunner_ntests_failed(runner_mult);

   srunner_free(runner_avg);
   srunner_free(runner_del);
   srunner_free(runner_add);
   srunner_free(runner_mult);

   return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
