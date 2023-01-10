#include "filter.h"

static float arr_mean(const int *pb_src, const int *pe_src)
{
    const int *pc_src = pb_src;
    float sum = 0.0;
    for (; pc_src < pe_src; pc_src++)
        sum += (float)*(pc_src);

    return (sum / (float)(pe_src - pb_src));
}

static int count_via_mean(const int *pb_src, const int *pe_src, size_t *new_count, float mean)
{
    const int *pc_src = pb_src;

    for (; pc_src < pe_src; pc_src++)
        if ((float)(*pc_src) > mean)
            (*new_count)++;

    if (*new_count < 1)
        return NO_NEW_ELEMS;

    return EXIT_SUCCESS;
}

int key(int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (((pb_src == NULL) || (pe_src == NULL)) || (pb_src >= pe_src))
        return INVALID_PARAMETERS;
    
    const int *j = pb_src;
    size_t new_count = 0;

    float mean = arr_mean(pb_src, pe_src);

    int rc = count_via_mean(pb_src, pe_src, &new_count, mean);
    if (rc != EXIT_SUCCESS)
        return rc;

    *pe_dst = pb_src + new_count;

    if (*pb_dst != NULL)
    {
        *pe_dst = *pb_dst + new_count;

        for (int *k = *pb_dst; (j < pe_src) && (k < *pe_dst); j++)
        {
            if ((float)*j > mean)
            {
                *k = *j;
                k++;
            }
        }
    }

    return EXIT_SUCCESS;
}














