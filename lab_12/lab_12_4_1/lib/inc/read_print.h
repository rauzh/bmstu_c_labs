#ifndef LAB_07_01_04_READ_PRINT_H
#define LAB_07_01_04_READ_PRINT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INVALID_INPUT_FOUND       0
#define MAX_LEN_LINE              512
#define EQ                        0

int get_arr_size(FILE *f);
void read_array(FILE *f, int *pb, const int *pe);
void write_array(FILE *f, int *pb, const int *pe);

#endif //LAB_07_01_04_READ_PRINT_H
