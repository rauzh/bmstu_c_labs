#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "types.h"
#include "funcs_sort.h"
#include "funcs_io.h"
#include "main_branches.h"

void put_number_by_pos(FILE *f, const size_t pos, const int num)
{
    fseek(f, (pos * sizeof(int)), SEEK_SET);
    fwrite(&num, sizeof(int), 1, f);
}

int get_number_by_pos(FILE *f, const size_t pos)
{
    int num;

    fseek(f, (pos * sizeof(int)), SEEK_SET);
    fread(&num, sizeof(int), 1, f);

    return num;
}

void swap_in_file(FILE *f, size_t i, size_t pos, int min, int tmp)
{
    put_number_by_pos(f, i, min);
    put_number_by_pos(f, pos, tmp);
}

void selections_sort_bin_file(FILE *f, const size_t count)
{
    size_t pos;
    int num, tmp, min;

    for (size_t i = 0; i < (count - 1); i++)
    {
        tmp = get_number_by_pos(f, i);
        min = tmp;
        pos = i;

        for (size_t j = i + 1; j < count; j++)
        {
            num = get_number_by_pos(f, j);

            if (num < min)
            {
                min = num;
                pos = j;
            }
        }

        if (pos != i)
            swap_in_file(f, i, pos, min, tmp);
    }
}

int sort_bin_file(FILE *f)
{
    size_t size;

    if ((get_size_file(f, &size) < 0) || (size % sizeof(int) != 0))
        return INVALID_FILE_SIZE;

    size /= sizeof(int);

    selections_sort_bin_file(f, size);

    return EXIT_SUCCESS;
}
