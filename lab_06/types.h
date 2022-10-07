#ifndef LAB_6_TYPES_H
#define LAB_6_TYPES_H

#include "defs.h"

typedef enum
{
    FALSE,
    TRUE = 1
} bool;

typedef struct
{
    char name[NAME_LEN_MAX + 1];
    double weight;
    double volume;
} items_t;

typedef const char *const arg_t;

#endif //LAB_6_TYPES_H
