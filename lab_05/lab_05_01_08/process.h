#ifndef __PROCESS_H__
#define __PROCESS_H__

#include "types.h"

int process(FILE *f);
int write_answer(int count_lcl_max, int lcl_maxes_min_dist);
void local_max_finder(int num, int prev, bool *prev_bigger_prevprev, int *count_lcl_max, int *lcl_max_prev, int *lcl_maxes_min_dist, int *i);

#endif
