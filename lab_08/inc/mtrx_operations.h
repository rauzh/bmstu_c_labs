#ifndef _LAB_08_03_01_MTRX_OPERATIONS_H
#define _LAB_08_03_01_MTRX_OPERATIONS_H

#include <stdint.h>

void del_to_square(int *n, int *m, int64_t ***mtrx_a, int *p, int *q, int64_t ***mtrx_b);
void del_columns(int *n, int *m, int64_t ***mtrx);
int get_line_to_del(int *n, int *m, int64_t ***mtrx);
void del_column(int *n, int *m, int64_t ***mtrx, int column);
void del_rows(int *n, int *m, int64_t ***mtrx);
void del_row(int *n, int *m, int64_t ***mtrx, int row);

int add_to_square(int *k, int64_t ***mtrx_a, int *s, int64_t ***mtrx_b, int *z);
int add_rows(int *s, int *z, int64_t ***mtrx);
void add_row(int s, int dim, int64_t ***mtrx);
int64_t get_avg_of_column(int n, int j, int64_t ***mtrx);
int add_columns(int *s, int *z, int64_t ***mtrx);
int64_t get_max_of_row(int i, int end, int64_t ***mtrx);

#endif //_LAB_08_03_01_MTRX_OPERATIONS_H
