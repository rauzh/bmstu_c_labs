#ifndef __READ_PRINT_LAB_10__
#define __READ_PRINT_LAB_10__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "types.h"


void list_fprintf(FILE *f, node_t *head);
int read_to_list(FILE *f, node_t **head_1, node_t **head_2, size_t *i, size_t *j);

#endif // __READ_PRINT_LAB_10__
