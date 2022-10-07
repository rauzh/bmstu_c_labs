#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "mem_operations.h"
//TODO: remake w realloc and make it universal
int64_t **allocate_matrix(int n, int m)
{
    int64_t **data;
    data = calloc(n, sizeof(int64_t*));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(int64_t));
        if (!data[i])
        {
            free_matrix(data, n);
            return NULL;
        }
    }

    return data;
}

void free_matrix(int64_t **data, int n)
{
    for (int i = 0; i < n; i++)
        free(data[i]);
    free(data);
}
