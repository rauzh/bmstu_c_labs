#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "check_calc_val.h"

int main(void)
{
   int no_failed = 0;
   Suite *s_calc_val;
   SRunner *runner_calc_val;

   s_calc_val = calc_val();

   runner_calc_val = srunner_create(s_calc_val);

   srunner_run_all(runner_calc_val, CK_VERBOSE);

   no_failed = srunner_ntests_failed(runner_calc_val);

   srunner_free(runner_calc_val);

   return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

