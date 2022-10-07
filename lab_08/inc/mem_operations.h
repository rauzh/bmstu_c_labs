#ifndef LAB_08_03_01_MTRX_OPERATIONS_H
#define LAB_08_03_01_MTRX_OPERATIONS_H

#include <stdint.h>

int64_t **allocate_matrix(int n, int m);
void free_matrix(int64_t **data, int n);

#endif //LAB_08_03_01_MTRX_OPERATIONS_H
