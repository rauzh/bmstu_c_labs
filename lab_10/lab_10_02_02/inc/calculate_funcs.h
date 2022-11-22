#ifndef __CALC_FUNCS_LAB_10__
#define __CALC_FUNCS_LAB_10__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "defs.h"
#include "types.h"

int calculate_value(node_t *pol, int x, int *res);
int calculate_print_ddx(node_t *pol);
int sum_polynoms(node_t *pol_a, node_t *pol_b);
int print_ratio_even_degrees(node_t *pol);

#endif
