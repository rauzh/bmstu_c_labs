#ifndef LAB_07_01_04_FINAL_FUNCS_H
#define LAB_07_01_04_FINAL_FUNCS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "types.h"

int sort_write_binary_search(arg_t argv[]);
int filter_sort_write(arg_t argv[]);
int print_array_to_file(arg_t argv[], int *pb, const int *pe);
int create_arr(FILE *f_in, int **arr, size_t *size);

#endif //LAB_07_01_04_FINAL_FUNCS_H
