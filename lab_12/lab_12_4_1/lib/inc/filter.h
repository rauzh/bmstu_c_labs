#ifndef LAB_07_01_03_FILTER_H
#define LAB_07_01_03_FILTER_H

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define NO_NEW_ELEMS        249
#define INVALID_PARAMETERS  250

int key(int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif //LAB_07_01_03_FILTER_H
