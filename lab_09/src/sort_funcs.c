#include <string.h>

#include "types.h"
#include "sort_funcs.h"

#define SWAP(x, y) { items_t SWAP = x; x = y; y = SWAP; }

void sort_by_density(items_t items[], size_t items_count)
{
    size_t i, j, max_idx;

    for (i = 0; i < items_count; i++)
    {
        max_idx = i;

        for (j = i + 1; j < items_count; j++)
            if ((items[j].weight / items[j].volume) < (items[max_idx].weight / items[max_idx].volume))
                max_idx = j;

        SWAP(items[i], items[max_idx]);
    }
}
