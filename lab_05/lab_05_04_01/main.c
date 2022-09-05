/**
исходя из правил в ИУ7-23
я родился 18.09 --> делаю:
    18 % 2 + 1 = 1 (студенты)
    9 % 2 + 1 = 2 (бинарник)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

#include "defs.h"
#include "types.h"
#include "stud_find.h"
#include "io_funcs.h"
#include "sort_funcs.h"
#include "stud_del.h"
#include "main_branches.h"

int main(int argc, const char *const argv[])
{
    if ((argc != 3) && (argc != 4) && (argc != 5))
        return INVALID_ARGS_AMOUNT;

    int rc;
    // сортануть студентов по фамилии и вторым ключом по имени
    if ((strcmp(argv[1], "sb") == EQUAL) && (argc == 3))
        rc = bin_file_stud_sorting(argv);
    else if ((strcmp(argv[1], "fb") == EQUAL) && (argc == 5))
        rc = bin_file_stud_finding(argv);
    else if ((strcmp(argv[1], "create") == EQUAL) && (argc == 4))
        rc = bin_file_create_stud_base(argv);
    else if ((strcmp(argv[1], "db") == EQUAL) && (argc == 3))
        rc = bin_file_delete_studs(argv);
    else
        return INVALID_ARGS;

    return rc;
}
