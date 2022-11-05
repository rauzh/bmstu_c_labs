#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "defs.h"
#include "types.h"
#include "final_funcs.h"
#include "read_print.h"
#include "sort_funcs.h"
#include "mem_funcs.h"

int realloc_struct_arr(items_t **items, size_t *new_len, size_t *cur_len)
{
    items_t *tmp = NULL;

    (*new_len) *= RESIZE_STEP;

    printf("%zu\n", *cur_len);

    tmp = realloc((*items), (*new_len) * sizeof(items_t));
    if (tmp == NULL)
        return MEMORY_ERROR;
    *items = tmp;

    return EXIT_SUCCESS;
}

void free_struct_arr(items_t *items, size_t items_count) 
{
    for (size_t i = 0; i < items_count; i++)
        free(items[i].name);

    free(items);
}
