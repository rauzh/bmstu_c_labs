#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "defs.h"
#include "types.h"
#include "stud_find.h"
#include "io_funcs.h"
#include "sort_funcs.h"

int find_by_surname(FILE *f, FILE *b, const char *const substr, const size_t count)
{
    size_t found_count = 0;
    student_t student;

    for (size_t i = 0; i < count; i++)
    {
        student = get_stud_by_pos(f, i);

        if (strstr(student.surname, substr) == &(student.surname[0]))
        {
            fwrite(&student, sizeof(student_t), 1, b);
            found_count++;
        }
    }

    if (found_count == 0)
        return NO_STUDS_FOUND;

    return EXIT_SUCCESS;
}

int stud_find(FILE *f, FILE *b, const char *const substr)
{
    size_t size;
    int rc = 0;

    if ((get_size_file(f, &size) < 0))
        return INVALID_FILE_SIZE;

    if (size % sizeof(student_t) != 0)
        return INVALID_FILE_SIZE;

    size /= sizeof(student_t);

    rc = find_by_surname(f, b, substr, size);

    return rc;
}
