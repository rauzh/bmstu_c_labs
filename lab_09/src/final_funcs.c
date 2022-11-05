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

#define INIT_FILE(file, file_to_open, mode)        \
     do {                                          \
        file = fopen(file_to_open, mode);          \
        if (file == NULL)                          \
            return NO_FILE;                        \
    } while(0)

#define CLOSE_FILE(file)                           \
     do {                                          \
        if (fclose(file) == END_OF_FILE_ERR)       \
            return CLOSE_FILE_ERROR;               \
    } while(0)

int items_info(arg_t argv[])
{
    FILE *f;
    int rc = EXIT_SUCCESS;
    INIT_FILE(f, argv[1], "r");
    items_t *items = calloc(START_ARR_LEN, sizeof(items_t));
    if (items == NULL)
        return MEMORY_ERROR;
    size_t items_count = 0;

    rc = read_to_array(f, &items, &items_count);

    CLOSE_FILE(f);
    if (rc != EXIT_SUCCESS)
        return rc;

    print_array(items, items_count);

    free_struct_arr(items, items_count);

    return rc;
}

int specific_items_info(arg_t argv[])
{
    FILE *f;
    int rc = EXIT_SUCCESS;
    INIT_FILE(f, argv[1], "r");
    items_t *items = calloc(START_ARR_LEN, sizeof(items_t));
    if (items == NULL)
        return MEMORY_ERROR;
    size_t items_count = 0;

    rc = read_to_array(f, &items, &items_count);

    CLOSE_FILE(f);
    if (rc != EXIT_SUCCESS)
        return rc;

    rc = print_specific_items(argv[2], items, items_count);

    free_struct_arr(items, items_count);

    return rc;
}

int sort_print_by_density(arg_t argv[])
{
    FILE *f;
    int rc = EXIT_SUCCESS;
    INIT_FILE(f, argv[1], "r");
    items_t *items = calloc(START_ARR_LEN, sizeof(items_t));
    if (items == NULL)
        return MEMORY_ERROR;
    size_t items_count = 0;

    rc = read_to_array(f, &items, &items_count);

    CLOSE_FILE(f);
    if (rc != EXIT_SUCCESS)
        return rc;

    sort_by_density(items, items_count);
    print_array(items, items_count);

    free_struct_arr(items, items_count);

    return rc;
}
