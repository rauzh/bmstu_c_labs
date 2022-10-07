#include <stdlib.h>
#include <stdio.h>

#include "read_print.h"
#include "mem_operations.h"
#include "mtrx_operations.h"
#include "mtrx_multiply.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main(void)
{
    int rc = EXIT_SUCCESS;
    int n, m, p, q, db, da;
    int64_t **mtrx_a = NULL, **mtrx_b = NULL, **res_mtrx = NULL;
    rc = input_first_session(&n, &m, &mtrx_a, &p, &q, &mtrx_b);
    if (rc == EXIT_SUCCESS)
    {
        del_to_square(&n, &m, &mtrx_a, &p, &q, &mtrx_b);

        int k = MIN(n, m), s = MIN(p, q), z = MAX(k, s);

        rc = add_to_square(&k, &mtrx_a, &s, &mtrx_b, &z);
        if (rc == EXIT_SUCCESS)
        {
            rc = input_degree(&da, &db);
            if (rc == EXIT_SUCCESS)
            {
                rc = multiplied_mtrx_output(z, &mtrx_a, da, &mtrx_b, db, &res_mtrx);
                if (rc == EXIT_SUCCESS)
                    free_matrix(res_mtrx, z);
            }
            free_matrix(mtrx_a, z);
            free_matrix(mtrx_b, z);
        }
        else
        {
            free_matrix(mtrx_a, k);
            free_matrix(mtrx_b, s);
        }
    }

    return rc;
}
