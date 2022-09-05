#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "types.h"
#include "funcs_sort.h"
#include "funcs_io.h"
#include "main_branches.h"

int bin_file_filling_task(const char *const argv[])
{
    FILE *f;
    int rc = EXIT_SUCCESS;
    f = fopen(argv[3], "wb");

    if (f == NULL)
        return NO_FILE;

    rc = fill_bin_file(f, argv[2]);

    fclose(f);

    return rc;
}

int bin_file_printing_task(const char *const argv[])
{
    FILE *f;
    int rc = EXIT_SUCCESS;
    f = fopen(argv[2], "rb");

    if (f == NULL)
        return NO_FILE;

    rc = print_bin_file(f);

    fclose(f);

    return rc;
}

int bin_file_sorting_task(const char *const argv[])
{
    FILE *f;
    int rc = EXIT_SUCCESS;
    f = fopen(argv[2], "r+b");

    if (f == NULL)
        return NO_FILE;

    rc = sort_bin_file(f);

    fclose(f);

    return rc;
}
