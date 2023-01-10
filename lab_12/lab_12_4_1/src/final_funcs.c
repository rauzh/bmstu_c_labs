#include "defs.h"
#include "final_funcs.h"
#include "read_print.h"
#include "sort_funcs.h"
#include "filter.h"

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


int sort_write_binary_search(arg_t argv[])
{
    FILE *f_in;
    int rc = EXIT_SUCCESS;

    INIT_FILE(f_in, argv[1], "r");

    size_t size;
    int *arr;
    rc = create_arr(f_in, &arr, &size);
    if (rc != EXIT_SUCCESS)
        return rc;

    CLOSE_FILE(f_in);

    mysort(arr, size, sizeof(int), (int(*)(const void *, const void *)) compare);
    rc = print_array_to_file(argv, arr, arr + size);

    return rc;
}


int filter_sort_write(arg_t argv[])
{
    FILE *f_in;
    int rc = EXIT_SUCCESS;

    INIT_FILE(f_in, argv[1], "r");

    size_t size;
    int *arr;
    rc = create_arr(f_in, &arr, &size);
    if (rc != EXIT_SUCCESS)
        return rc;

    CLOSE_FILE(f_in);

    int *arr_dst = NULL, *arr_dst_end = NULL;

    rc = key(arr, arr + size, &arr_dst, &arr_dst_end);
    if (rc != EXIT_SUCCESS)
    {
        free(arr);
        return rc;
    }

    arr_dst = malloc((arr_dst_end - arr) * sizeof(int));

    if (arr_dst == NULL)
    {
        free(arr);
        return MEMORY_ERROR;
    }

    key(arr, arr + size, &arr_dst, &arr_dst_end);

    free(arr);

    mysort(arr_dst, (arr_dst_end - arr_dst), sizeof(int), (int(*)(const void *, const void *)) compare);
    rc = print_array_to_file(argv, arr_dst, arr_dst_end);

    return rc;
}

int print_array_to_file(arg_t argv[], int *pb, const int *pe)
{
    FILE *f_out;
    f_out = fopen(argv[2], "w");
    if (f_out == NULL)
    {
        free(pb);
        return NO_FILE;
    }

    write_array(f_out, pb, pe);

    free(pb);
    CLOSE_FILE(f_out);

    return EXIT_SUCCESS;
}

int create_arr(FILE *f_in, int **arr, size_t *size)
{
    *size = get_arr_size(f_in);
    if (*size < 1)
        return INVALID_INPUT;

    rewind(f_in);
    *arr = malloc(*size * sizeof(int));
    if (arr == NULL)
        return MEMORY_ERROR;

    read_array(f_in, *arr, (*arr) + *size);

    return EXIT_SUCCESS;
}
