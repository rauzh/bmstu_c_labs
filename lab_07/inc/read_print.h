#ifndef LAB_07_01_04_READ_PRINT_H
#define LAB_07_01_04_READ_PRINT_H

#include "types.h"

int get_arr_size(FILE *f);
int fill_array(FILE *f, int *pb, const int *pe);
void write_array(FILE *f, int *pb, const int *pe);

#endif //LAB_07_01_04_READ_PRINT_H
