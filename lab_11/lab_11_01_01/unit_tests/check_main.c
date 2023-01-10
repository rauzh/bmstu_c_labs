#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "check_snprintf.h"

int main(void)
{
   int no_failed = 0;
   Suite *s_snprintf;
   SRunner *runner_snprintf;

   s_snprintf = check_my_snprintf();

   runner_snprintf = srunner_create(s_snprintf);

   srunner_run_all(runner_snprintf, CK_VERBOSE);

   no_failed = srunner_ntests_failed(runner_snprintf);

   srunner_free(runner_snprintf);

   return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
