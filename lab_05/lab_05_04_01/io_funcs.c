#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "defs.h"
#include "types.h"
#include "stud_find.h"
#include "io_funcs.h"
#include "sort_funcs.h"

void put_stud_by_pos(FILE *f, const size_t pos, const student_t student)
{
    fseek(f, (pos * sizeof(student_t)), SEEK_SET);
    fwrite(&student, sizeof(student_t), 1, f);
}

student_t get_stud_by_pos(FILE *f, const size_t pos)
{
    student_t student;

    fseek(f, (pos * sizeof(student_t)), SEEK_SET);
    fread(&student, sizeof(student_t), 1, f);

    return student;
}

int get_size_file(FILE *f, size_t *size)
{
    long current_size;

    if (fseek(f, 0, SEEK_END))
        return INVALID_FILE_SIZE;

    current_size = ftell(f);

    if (current_size < 0)
        return INVALID_FILE_SIZE;

    *size = current_size;

    fseek(f, 0, SEEK_SET);

    return EXIT_SUCCESS;
}

int fill_bin_file(FILE *f, const char *const str_count)
{
    int digital_count;
    student_t student;

    if (strspn(str_count, DIGITS) != strlen(str_count))
        return INVALID_COUNT_ARG;

    digital_count = atoi(str_count);
    if (digital_count == 0)
        return ZERO_COUNT;

    while (digital_count > 0)
    {
        scanf("%s", student.surname);
        scanf("%s", student.name);
        scanf("%u", &(student.grades[0]));
        scanf("%u", &(student.grades[1]));
        scanf("%u", &(student.grades[2]));
        scanf("%u", &(student.grades[3]));

        fwrite(&student, sizeof(int), 1, f);
        digital_count--;
    }

    return EXIT_SUCCESS;
}

int print_bin_file(FILE *f)
{
    size_t size;
    student_t student;

    if (get_size_file(f, &size))
        return INVALID_FILE_SIZE;

    if (size % sizeof(student_t) != 0)
        return INVALID_FILE_SIZE;

    size /= sizeof(student_t);

    for (size_t i = 0; i < size; i++)
    {
        fread(&student, sizeof(student_t), 1, f);
        fprintf(stdout, "%s\n", student.surname);
        fprintf(stdout, "%s\n", student.name);

        for (size_t j = 0; j < GRADES_AMOUNT; j++)
            fprintf(stdout, "%u ", student.grades[j]);
    }

    fprintf(stdout, "\n");

    return EXIT_SUCCESS;
}
