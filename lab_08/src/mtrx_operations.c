#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "mtrx_operations.h"
#include "read_print.h"
#include "mem_operations.h"
#include "mtrx_multiply.h"
#include "defs.h"

void del_to_square(int *n, int *m, int64_t ***mtrx_a, int *p, int *q, int64_t ***mtrx_b)
{
    del_columns(n, m, mtrx_a);
    del_rows(n, m, mtrx_a);

    del_columns(p, q, mtrx_b);
    del_rows(p, q, mtrx_b);
}

void del_columns(int *n, int *m, int64_t ***mtrx)
{
    if (*m < *n)
        return;
    int line_to_del = 0;

    while (*m > *n)
    {
        line_to_del = get_line_to_del(n, m, mtrx);

        del_column(n, m, mtrx, line_to_del);
    }
}

void del_rows(int *n, int *m, int64_t ***mtrx)
{
    if (*n < *m)
        return;
    int line_to_del = 0;

    while (*n > *m)
    {
        line_to_del = get_line_to_del(n, m, mtrx);

        del_row(n, m, mtrx, line_to_del);
    }
}

int get_line_to_del(int *n, int *m, int64_t ***mtrx)
{
    int line_to_del = 0, max = (*mtrx)[0][0];
    for (int j = 0; j < *m; j++)
        for (int i = 0; i < *n; i++)
            if ((*mtrx)[i][j] > max)
            {
                max = (*mtrx)[i][j];
                line_to_del = (*m > *n) ? j : i;
            }

    return line_to_del;
}

void del_column(int *n, int *m, int64_t ***mtrx, int column)
{
    (*m)--;

    for (int i = 0; i < *n; i++)
    {
        for (int j = column; j < *m; j++)
            (*mtrx)[i][j] = (*mtrx)[i][j + 1];
        (*mtrx)[i] = realloc((*mtrx)[i], sizeof(int64_t) * (*m));
    }
}

void del_row(int *n, int *m, int64_t ***mtrx, int row)
{
    (*n)--;

    for (int i = row; i < *n; i++)
        memcpy((*mtrx)[i], (*mtrx)[i + 1], sizeof(int64_t) * (*m));

    free((*mtrx)[*n]);
    (*mtrx) = realloc((*mtrx), sizeof(int64_t *) * (*n));
}

// =====================================================================================================================
int add_to_square(int *k, int64_t ***mtrx_a, int *s, int64_t ***mtrx_b, int *z)
{
    int rc = EXIT_SUCCESS;

    rc = add_rows(k, z, mtrx_a);
    rc = add_columns(k, z, mtrx_a);
    if (rc != EXIT_SUCCESS)
    {
        free_matrix(*mtrx_a, *k);
        free_matrix(*mtrx_b, *s);
        return rc;
    }

    rc = add_rows(s, z, mtrx_b);
    rc = add_columns(s, z, mtrx_b);
    if (rc != EXIT_SUCCESS)
    {
        free_matrix(*mtrx_a, *z);
        free_matrix(*mtrx_b, *s);
    }

    return rc;
}

int add_rows(int *s, int *z, int64_t ***mtrx)
{
    if (*z == *s)
        return EXIT_SUCCESS;
    int64_t **tmp_ptr = NULL;
    tmp_ptr = allocate_matrix(*z, *z);
    if (tmp_ptr == NULL)
        return MEMORY_ERROR;
    assign_mtrx(&tmp_ptr, mtrx, *s);
    free_matrix(*mtrx, *s);
    
    *mtrx = allocate_matrix(*z, *z);
    if (*mtrx == NULL)
        return MEMORY_ERROR;

    assign_mtrx(mtrx, &tmp_ptr, *s);
    free_matrix(tmp_ptr, *z);

    int dim = *s, count = *z - *s;
    for (int x = 0; x < count; x++)
        add_row((*s) + x, dim, mtrx);

    return EXIT_SUCCESS;
}

void add_row(int s, int dim, int64_t ***mtrx)
{
    for (int j = 0; j < dim; j++)
    {
        (*mtrx)[s][j] = get_avg_of_column(s, j, mtrx);
    }
}

int64_t get_avg_of_column(int n, int j, int64_t ***mtrx)
{
    int64_t sum = 0;
    for (int i = 0; i < n; i++)
        sum += (*mtrx)[i][j];

    if (sum % n == 0)
        return (sum / n);

    return (sum / n) >= 0 ? (sum / n) : (sum / n) - 1;
}

int add_columns(int *s, int *z, int64_t ***mtrx)
{
    if (*z == *s)
        return EXIT_SUCCESS;

    int dim = *s;
    for (int i = 0; i < *z; i++)
        for (int j = dim; j < *z; j++)
            (*mtrx)[i][j] = get_max_of_row(i, j, mtrx);

    return EXIT_SUCCESS;
}

int64_t get_max_of_row(int i, int end, int64_t ***mtrx)
{
    int64_t max = (*mtrx)[i][0];
    for (int j = 0; j < end; j++)
        if ((*mtrx)[i][j] > max)
            max = (*mtrx)[i][j];

    return max;
}
