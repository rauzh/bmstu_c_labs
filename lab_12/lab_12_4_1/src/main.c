#include <string.h>

#include "defs.h"
#include "types.h"
#include "final_funcs.h"

int main(int argc, arg_t argv[])
{
    if ((argc != 3) && (argc != 4))
        return INVALID_ARGS_AMOUNT;

    int rc = 0;

    if (argc == 3)
        rc = sort_write_binary_search(argv);
    else if ((strcmp(argv[3], "f") == EQUAL))
        rc = filter_sort_write(argv);
    else
        rc = INVALID_ARGS;

    return rc;
}
