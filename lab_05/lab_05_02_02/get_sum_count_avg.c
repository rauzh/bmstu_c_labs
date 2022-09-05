#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"
#include "defs.h"
#include "types.h"

int get_sum_count_avg(FILE *f, double *sum, double *count, double *avg)
{
    double num;

    while (fscanf(f, "%lf", &num) == CORRECT_NUM)
    {
        (*sum) += num;
        (*count)++;
    }

    if ((*count) < 1)
        return NO_NUMS;

    (*avg) = (*sum) / (*count);

    return EXIT_SUCCESS;
}
