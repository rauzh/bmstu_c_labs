#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdint.h>

#define SURNAME_LEN_MAX 25
#define NAME_LEN_MAX    10
#define GRADES_AMOUNT   4

typedef enum
{
    FALSE,
    TRUE = 1
} bool;

typedef struct
{
    char surname[SURNAME_LEN_MAX + 1];
    char name[NAME_LEN_MAX + 1];
    uint32_t grades[GRADES_AMOUNT];
} student_t;

#endif
