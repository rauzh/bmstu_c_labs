#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include "sort_funcs.h"
#include "defs.h"

int compare(const int *i, const int *j)
{
    return *i - *j;
}

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    if (num == 0)
        return;
    char *lo = NULL, *hi = NULL, *mid = NULL, *pcur = base;
    const char *pe = pcur + (num * size);
    char *key = malloc(size);

    while (pcur < pe)
    {
        memcpy(key, pcur, size);
        lo = base;
        hi = pcur;
        while (lo < hi)
        {
            mid = lo + (hi - lo) / size / 2 * size;
            if ((*compare)(pcur, mid) < 0)
                hi = mid;
            else
                lo = mid + size;
        }
        for (char *pcur_cp = pcur; pcur_cp > lo; pcur_cp -= size)
            memcpy(pcur_cp, pcur_cp - size, size);

        memcpy(lo, key, size);

        pcur += size;
    }
    free(key);
}
