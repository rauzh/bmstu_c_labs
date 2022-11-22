#include <stdio.h>

#include "defs.h"
#include "types.h"
#include "final_funcs.h"
#include "read_print.h"

int main(void)
{
    int rc = 0;
    command_t command_num = 0;
    char command[COMMAND_LEN];

    rc = input_command(command, &command_num);
    if (rc != EXIT_SUCCESS)
        return rc;

    switch (command_num)
    {
        case GET_VAL:
            rc = find_polynom_value();
            break;
        case GET_DDX:
            rc = find_polynom_ddx();
            break;
        case GET_SUM:
            rc = find_polynoms_sum();
            break;
        case GET_DVD:
            rc = find_polynom_evenities();
            break;
    }

    return rc;
}
