#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "read_print.h"
#include "mem_operations.h"
#include "defs.h"

int input_mtrx(int64_t **mtrx, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%ld", &mtrx[i][j]) != 1)
            {
                free_matrix(mtrx, n);
                return INPUT_ERROR;
            }

    return EXIT_SUCCESS;
}

void output_mtrx(int64_t **mtrx, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%ld ", mtrx[i][j]);
        puts("");
    }
}

int input_dimensions(int *n, int *m)
{
    if (scanf("%d %d", n, m) != 2)
        return INPUT_ERROR;
    if (*n <= 0 || *m <= 0)
        return INPUT_ERROR;

    return EXIT_SUCCESS;
}

int input_degree(int *n, int *m)
{
    if (scanf("%d %d", n, m) != 2)
        return INPUT_ERROR;
    if (*n < 0 || *m < 0)
        return INPUT_ERROR;

    return EXIT_SUCCESS;
}

int input_first_session(int *n, int *m, int64_t ***mtrx_a, int *p, int *q, int64_t ***mtrx_b)
{
    int rc = EXIT_SUCCESS;

    rc = input_dimensions(n, m);
    if (rc != EXIT_SUCCESS)
        return rc;

    *mtrx_a = allocate_matrix(*n, *m);
    if (*mtrx_a == NULL)
        return MEMORY_ERROR;

    rc = input_mtrx(*mtrx_a, *n, *m);
    if (rc != EXIT_SUCCESS)
        return rc;

    rc = input_dimensions(p, q);
    if (rc != EXIT_SUCCESS)
    {
        free_matrix(*mtrx_a, *n);
        return rc;
    }

    *mtrx_b = allocate_matrix(*p, *q);
    if (mtrx_b == NULL)
    {
        free_matrix(*mtrx_a, *n);
        return MEMORY_ERROR;
    }

    rc = input_mtrx(*mtrx_b, *p, *q);
    if (rc != EXIT_SUCCESS)
    {
        free_matrix(*mtrx_a, *n);
        return rc;
    }

    return EXIT_SUCCESS;
}
