#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "check_find.h"
#include "check_pop_back.h"
#include "check_pop_front.h"
#include "check_remove_dupl.h"
#include "check_sort.h"

int main(void)
{
   int no_failed = 0;
   Suite *s_pop_back, *s_find, *s_pop_front, *s_remove_dupl, *s_sort;
   SRunner *runner_pop_back, *runner_find, *runner_pop_front, *runner_remove_dupl, *runner_sort;

   s_find = check_find();
   s_pop_back = check_pop_back();
   s_pop_front = check_pop_front();
   s_remove_dupl = check_remove_dupl();
   s_sort = check_sort();

   runner_find = srunner_create(s_find);
   runner_pop_back = srunner_create(s_pop_back);
   runner_pop_front = srunner_create(s_pop_front);
   runner_remove_dupl = srunner_create(s_remove_dupl);
   runner_sort = srunner_create(s_sort);

   srunner_run_all(runner_find, CK_VERBOSE);
   srunner_run_all(runner_pop_back, CK_VERBOSE);
   srunner_run_all(runner_pop_front, CK_VERBOSE);
   srunner_run_all(runner_remove_dupl, CK_VERBOSE);
   srunner_run_all(runner_sort, CK_VERBOSE);

   no_failed = srunner_ntests_failed(runner_find);
   no_failed += srunner_ntests_failed(runner_pop_back);
   no_failed += srunner_ntests_failed(runner_pop_front);
   no_failed += srunner_ntests_failed(runner_remove_dupl);
   no_failed += srunner_ntests_failed(runner_sort);

   srunner_free(runner_find);
   srunner_free(runner_pop_back);
   srunner_free(runner_pop_front);
   srunner_free(runner_remove_dupl);
   srunner_free(runner_sort);

   return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
