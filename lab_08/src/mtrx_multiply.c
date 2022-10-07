#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "mtrx_operations.h"
#include "mtrx_multiply.h"
#include "read_print.h"
#include "mem_operations.h"
#include "defs.h"


void multiply_mtrx(int z, int64_t ***mtrx_a, int64_t ***mtrx_b, int64_t ***res_mtrx)
{
    for (int i = 0; i < z; i++)
        for (int j = 0; j < z; j++)
        {
            (*res_mtrx)[i][j] = 0;
            for (int k = 0; k < z; k++)
                (*res_mtrx)[i][j] += (*mtrx_a)[i][k] * (*mtrx_b)[k][j];
        }
}

void assign_mtrx(int64_t ***mtrx_to, int64_t ***mtrx_from, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            (*mtrx_to)[i][j] = (*mtrx_from)[i][j];
}

int multiplied_mtrx_output(int z, int64_t ***mtrx_a, int da, int64_t ***mtrx_b, int db, int64_t ***res_mtrx)
{
    *res_mtrx = allocate_matrix(z, z);
    if (*res_mtrx == NULL)
        return MEMORY_ERROR;
    int64_t **tmp_1_mtrx = NULL;
    tmp_1_mtrx = allocate_matrix(z, z);
    if (tmp_1_mtrx == NULL)
    {
        free_matrix(*res_mtrx, z);
        return MEMORY_ERROR;
    }

    for (int i = 0; i < z; i++)
        for (int j = 0; j < z; j++)
            (*res_mtrx)[i][j] = (i == j) ? 1 : 0;


    for (int count = 0; count < da; count++)
    {
        assign_mtrx(&tmp_1_mtrx, res_mtrx, z);
        multiply_mtrx(z, &tmp_1_mtrx, mtrx_a, res_mtrx);
    }
    for (int count = 0; count < db; count++)
    {
        assign_mtrx(&tmp_1_mtrx, res_mtrx, z);
        multiply_mtrx(z, &tmp_1_mtrx, mtrx_b, res_mtrx);
    }
    
    output_mtrx(*res_mtrx, z, z);
    free_matrix(tmp_1_mtrx, z);
    return EXIT_SUCCESS;
}
