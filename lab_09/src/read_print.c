#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "types.h"
#include "read_print.h"
#include "mem_funcs.h"

#define RETURN_AND_FREE(err_code)            \
            do {                             \
            free((*items)[(*i)].name);       \
            free_struct_arr((*items), *i);   \
            return err_code; } while(0)

int read_to_array(FILE *f, items_t **items, size_t *i)
{
    int rc;
    size_t name_len = 0, cur_len = START_ARR_LEN;
    char end_line;

    (*items)[(*i)].name = NULL;
    while ((getline(&((*items)[(*i)].name), &name_len, f) != GETLINE_ERR))
    {
        if (((*items)[(*i)].name[strlen((*items)[(*i)].name) - 1] != '\n') || (strlen((*items)[(*i)].name) <= 1))
            RETURN_AND_FREE(INVALID_INPUT);
        (*items)[(*i)].name[strlen((*items)[(*i)].name) - 1] = '\0';

        rc = fscanf(f, "%lf%c", &((*items)[(*i)].weight), &end_line);
        if ((rc != (CORRECT_FIELD + 1)) || (end_line != '\n') || ((*items)[(*i)].weight <= 0))
            RETURN_AND_FREE(INVALID_INPUT);

        rc = fscanf(f, "%lf%c", &((*items)[(*i)].volume), &end_line);
        if ((rc <= 0) || ((rc == (CORRECT_FIELD + 1)) && (end_line != '\n')) || ((*items)[(*i)].volume <= 0))
            RETURN_AND_FREE(INVALID_INPUT);

        (*i)++;
        if ((*i) == cur_len)
        {
            rc = realloc_struct_arr(items, &cur_len, i);
            if (rc != EXIT_SUCCESS)
                RETURN_AND_FREE(rc);
        }
        (*items)[(*i)].name = NULL;
    }
    
    if ((*i) == 0)
        RETURN_AND_FREE(EMPTY_FILE);

    free((*items)[(*i)].name);
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
