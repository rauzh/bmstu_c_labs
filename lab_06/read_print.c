#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "types.h"
#include "read_print.h"

int read_to_array(FILE *f, items_t items[], size_t *i)
{
    int rc;
    char end_line;
    while (((*i) < MAX_ARR_LEN) &&
           (fscanf(f, "%s\n", items[(*i)].name)) == CORRECT_FIELD)
    {
        if (strlen(items[(*i)].name) > NAME_LEN_MAX)
            return OVERFLOW;

        rc = fscanf(f, "%lf%c", &(items[(*i)].weight), &end_line);
        if ((rc != (CORRECT_FIELD + 1)) || (end_line != '\n') || (items[(*i)].weight <= 0))
            return INVALID_INPUT;

        rc = fscanf(f, "%lf%c", &(items[(*i)].volume), &end_line);
        if ((rc <= 0) || ((rc == (CORRECT_FIELD + 1)) && (end_line != '\n')) || (items[(*i)].volume <= 0))
            return INVALID_INPUT;

        (*i)++;
    }

    if ((*i) == MAX_ARR_LEN)
        return OVERFLOW;

    if ((*i) == 0)
        return EMPTY_FILE;

    return EXIT_SUCCESS;
}

void print_array(items_t items[], size_t items_count)
{
    for (size_t i = 0; i < items_count; i++)
        fprintf(stdout, "%s\n%lf\n%lf\n", items[i].name, items[i].weight, items[i].volume);
}

int print_specific_items(arg_t start, items_t items[], size_t items_count)
{
    int count = 0;
    for (size_t i = 0; i < items_count; i++)
    {
        if (strncmp(start, items[i].name, strlen(start)) == EQUAL)
        {
            count++;
            fprintf(stdout, "%s\n%lf\n%lf\n", items[i].name, items[i].weight, items[i].volume);
        }
    }

    if (count == 0)
        return NO_SPECIFIC_ITEM;

    return EXIT_SUCCESS;
}