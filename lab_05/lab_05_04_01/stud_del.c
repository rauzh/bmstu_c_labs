#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#include "defs.h"
#include "types.h"
#include "stud_find.h"
#include "io_funcs.h"
#include "sort_funcs.h"
#include "stud_del.h"

double get_average_by_pos(FILE *f, const size_t pos)
{
    student_t student;
    uint32_t grades_sum = 0;

    student = get_stud_by_pos(f, pos);

    for (size_t i = 0; i < GRADES_AMOUNT; i++)
        grades_sum += student.grades[i];

    return (grades_sum / GRADES_AMOUNT);
}

double get_average_of_all_studs(FILE *f, const size_t count)
{
    double grades_sum = 0;

    for (size_t i = 0; i < count; i++)
        grades_sum += get_average_by_pos(f, i);

    return (grades_sum / count);
}

void del_stud_by_pos(FILE *f, const size_t pos, const size_t count)
{
    student_t student;

    for (size_t i = pos; i < (count - 1); i++)
    {
        student = get_stud_by_pos(f, i + 1);
        put_stud_by_pos(f, i, student);
    }
}

void delete_studs_w_min_average(FILE *f, size_t *count, const double average_of_all_studs)
{
    double average;
    size_t i = 0;

    while (i < *count)
    {
        average = get_average_by_pos(f, i);

        if (average < average_of_all_studs)
        {
            del_stud_by_pos(f, i, *count);
            (*count)--;
            i--;
        }

        i++;
    }
}

int stud_del(FILE *f)
{
    size_t size;
    double average_of_all_studs;

    if (get_size_file(f, &size) < 0)
        return INVALID_FILE_SIZE;

    if (size % sizeof(student_t) != 0)
        return INVALID_FILE_SIZE;

    size /= sizeof(student_t);

    if (size < 1)
        return EMPTY_FILE;

    average_of_all_studs = get_average_of_all_studs(f, size);

    delete_studs_w_min_average(f, &size, average_of_all_studs);

    ftruncate(fileno(f), size * sizeof(student_t));

    return EXIT_SUCCESS;
}
