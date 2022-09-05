#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"
#include "defs.h"
#include "types.h"

int get_disp(FILE *f, double count, double avg, double *disp)
{
    double math_expectation = 0, num;

    while (fscanf(f, "%lf", &num) == CORRECT_NUM)
        math_expectation += (num - avg) * (num - avg);

    (*disp) = math_expectation / count;

    return EXIT_SUCCESS;
}
