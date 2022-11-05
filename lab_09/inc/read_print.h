#ifndef LAB_6_READPRINT_H
#define LAB_6_READPRINT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "types.h"
#include "read_print.h"
#include "mem_funcs.h"

void print_array(items_t items[], size_t items_count);
int read_to_array(FILE *f, items_t **items, size_t *i);
int print_specific_items(arg_t start, items_t items[], size_t items_count);

#endif //LAB_6_READPRINT_H
