#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "check_sort.h"
#include "check_specify.h"
int main(void)
{
   int no_failed = 0;
   Suite *s_sort, *s_specify;
   SRunner *runner_sort, *runner_specify;

   s_sort = arr_sort();
   s_specify = arr_specify();

   runner_sort = srunner_create(s_sort);
   runner_specify = srunner_create(s_specify);

   srunner_run_all(runner_sort, CK_VERBOSE);
   srunner_run_all(runner_specify, CK_VERBOSE);

   no_failed = srunner_ntests_failed(runner_sort);
   no_failed += srunner_ntests_failed(runner_specify);

   srunner_free(runner_sort);
   srunner_free(runner_specify);

   return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
