#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "read_print.h"

int get_arr_size(FILE *f)
{
    char tmp[MAX_LEN];
    int size = 0;
    while (fscanf(f, "%s", tmp) != EOF)
    {
        if ((atoi(tmp) != 0) || (strcmp(tmp, "0") == EQUAL))
            size++;
        else
            return INVALID_INPUT_FOUND;
    }

    return size;
}

int fill_array(FILE *f, int *pb, const int *pe)
{
    while (pb < pe)
    {
        if (fscanf(f, "%d", pb) != 1)
            return INVALID_INPUT;

        pb++;
    }
    return EXIT_SUCCESS;
}

void write_array(FILE *f, int *pb, const int *pe)
{
    while (pb < pe)
    {
        fprintf(f, "%d ", *pb);
        pb++;
    }
    fprintf(f, "\n");
}
