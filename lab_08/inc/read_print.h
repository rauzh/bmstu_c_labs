#ifndef LAB_08_03_01_READ_PRINT_H
#define LAB_08_03_01_READ_PRINT_H

#include <stdint.h>

int input_mtrx(int64_t **mtrx, int n, int m);
void output_mtrx(int64_t **mtrx, int n, int m);
int input_dimensions(int *n, int *m);
int input_degree(int *n, int *m);
int input_first_session(int *n, int *m, int64_t ***mtrx_a, int *p, int *q, int64_t ***mtrx_b);

#endif //LAB_08_03_01_READ_PRINT_H
