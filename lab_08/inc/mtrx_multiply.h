#ifndef _LAB_08_03_01_MTRX_MULTIPLY_H
#define _LAB_08_03_01_MTRX_MULTIPLY_H

#include <stdint.h>

void multiply_mtrx(int z, int64_t ***mtrx_a, int64_t ***mtrx_b, int64_t ***res_mtrx);
int multiplied_mtrx_output(int z, int64_t ***mtrx_a, int da, int64_t ***mtrx_b, int db, int64_t ***res_mtrx);
void assign_mtrx(int64_t ***mtrx_to, int64_t ***mtrx_from, int size);

#endif //_LAB_08_03_01_MTRX_MULTIPLY_H
