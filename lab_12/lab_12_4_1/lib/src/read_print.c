#include "read_print.h"

int get_arr_size(FILE *f)
{
    char tmp[MAX_LEN_LINE];
    int size = 0;
    while (fscanf(f, "%s", tmp) != EOF)
    {
        if ((atoi(tmp) != 0) || (strcmp(tmp, "0") == EQ))
            size++;
        else
            return INVALID_INPUT_FOUND;
    }

    return size;
}

void read_array(FILE *f, int *pb, const int *pe)
{
    for (; pb < pe; pb++)
        fscanf(f, "%d", pb);
}

void write_array(FILE *f, int *pb, const int *pe)
{
    for (; pb < pe; pb++)
        fprintf(f, "%d ", *pb);
    fprintf(f, "\n");
}
