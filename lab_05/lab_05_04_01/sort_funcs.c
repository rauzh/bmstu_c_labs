#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "defs.h"
#include "types.h"
#include "stud_find.h"
#include "io_funcs.h"
#include "sort_funcs.h"

void selections_sort_stud(FILE *f, const size_t count)
{
    size_t pos;
    student_t student, cur, min;

    for (size_t i = 0; i < (count - 1); i++)
    {
        student = get_stud_by_pos(f, i);
        min = student;
        pos = i;

        for (size_t j = i + 1; j < count; j++)
        {
            cur = get_stud_by_pos(f, j);

            if ((strncmp(cur.surname, min.surname, 101) < EQUAL) ||
                ((strncmp(cur.surname, min.surname, 101) == EQUAL) &&
                (strncmp(cur.name, min.name, 101) < EQUAL)))
            {
                min = cur;
                pos = j;
            }
        }

		// swap
        if (pos != i)
        {
            put_stud_by_pos(f, i, min);
            put_stud_by_pos(f, pos, student);
        }
    }
}

int stud_sort(FILE *f)
{
    size_t size;

    if ((get_size_file(f, &size) < 0))
        return INVALID_FILE_SIZE;

    if ((size % sizeof(student_t) != 0))
        return INVALID_FILE_SIZE;

    size /= sizeof(student_t);

    if (size < 1)
        return EMPTY_FILE;

    selections_sort_stud(f, size);

    print_bin_file(f);

    return EXIT_SUCCESS;
}
