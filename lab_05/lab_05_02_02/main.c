#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"
#include "defs.h"
#include "types.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
        return NO_FILE;

    int rc;

    FILE *f = fopen(argv[1], "r");

    double sum = 0, count = 0, avg;
    rc = get_sum_count_avg(f, &sum, &count, &avg);

    if (rc != EXIT_SUCCESS)
        return rc;

    fclose(f);

    f = fopen(argv[1], "r");

    double disp = 0;
    get_disp(f, count, avg, &disp);

    fclose(f);

    printf("%lf\n", disp);

    return EXIT_SUCCESS;
}
