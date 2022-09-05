#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "types.h"
#include "funcs_sort.h"
#include "funcs_io.h"
#include "main_branches.h"

int get_size_file(FILE *f, size_t *size)
{
    long current_size;

    if (fseek(f, 0, SEEK_END))
        return INVALID_FILE_SIZE;

    current_size = ftell(f);

    if (current_size <= 0)
        return INVALID_FILE_SIZE;

    *size = current_size;

    fseek(f, 0, SEEK_SET);

    return EXIT_SUCCESS;
}

int fill_bin_file(FILE *f, const char *const str_count)
{
    int num, digital_count;

    if (strspn(str_count, DIGITS) != strlen(str_count))
        return INVALID_COUNT_ARG;

    digital_count = atoi(str_count);
    if (digital_count == 0)
        return ZERO_COUNT;

    do
    {
        num = rand();
        fwrite(&num, sizeof(int), 1, f);
        digital_count--;
    }
    while (digital_count > 0);

    return EXIT_SUCCESS;
}

int print_bin_file(FILE *f)
{
    size_t size;
    int num;

    if (get_size_file(f, &size))
        return INVALID_FILE_SIZE;

    if (size % sizeof(int) != 0)
        return INVALID_FILE_SIZE;

    size /= sizeof(int);

    for (size_t i = 0; i < size; i++)
    {
        fread(&num, sizeof(int), 1, f);
        fprintf(stdout, "%d ", num);
    }

    printf("\n");

    return EXIT_SUCCESS;
}
