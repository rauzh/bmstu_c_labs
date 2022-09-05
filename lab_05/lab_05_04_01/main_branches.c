#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

#include "defs.h"
#include "types.h"
#include "stud_find.h"
#include "io_funcs.h"
#include "sort_funcs.h"
#include "stud_del.h"
#include "main_branches.h"

int bin_file_stud_sorting(const char *const argv[])
{
    FILE *f;
    int rc = EXIT_SUCCESS;
    f = fopen(argv[2], "r+b");

    if (f == NULL)
        return NO_FILE;

    rc = stud_sort(f);

    fclose(f);

    return rc;
}

int bin_file_stud_finding(const char *const argv[])
{
    FILE *f;
    FILE *b;
    int rc = EXIT_SUCCESS;

    f = fopen(argv[2], "rb");
    b = fopen(argv[3], "wb");

    if (f == NULL)
        return NO_FILE;

    if (b == NULL)
        return NO_FILE;

    rc = stud_find(f, b, argv[4]);

    fclose(f);
    fclose(b);

    return rc;
}

int bin_file_create_stud_base(const char *const argv[])
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

int bin_file_delete_studs(const char *const argv[])
{
    FILE *f;
    int rc = EXIT_SUCCESS;

    f = fopen(argv[2], "r+b");

    if (f == NULL)
        return NO_FILE;

    rc = stud_del(f);

    fclose(f);

    return rc;
}
