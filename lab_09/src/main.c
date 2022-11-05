#include <string.h>

#include "defs.h"
#include "final_funcs.h"
#include "types.h"
#include "mem_funcs.h"

int main(int argc, arg_t argv[])
{
    if ((argc != 2) && (argc != 3))
        return INVALID_ARGS_AMOUNT;

    int rc;

    if (argc == 2)
        rc = sort_print_by_density(argv);
    else if ((strcmp(argv[2], "ALL") == EQUAL))
        rc = items_info(argv);
    else
        rc = specific_items_info(argv);

    return rc;
}
