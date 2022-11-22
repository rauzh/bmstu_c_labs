#ifndef __READ_PRINT_LAB_10__
#define __READ_PRINT_LAB_10__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "types.h"
#include "defs.h"

int input_command(char *com, command_t *com_num);
void polynom_print(node_t *head);
int input_polynom(node_t **pol);
int input_value(int *value);

#endif // __READ_PRINT_LAB_10__
