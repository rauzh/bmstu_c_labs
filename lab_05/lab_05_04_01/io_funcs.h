#ifndef __FIO_H__
#define __FIO_H__

void put_stud_by_pos(FILE *f, const size_t pos, const student_t student);
student_t get_stud_by_pos(FILE *f, const size_t pos);
int get_size_file(FILE *f, size_t *size);
int fill_bin_file(FILE *f, const char *const str_count);
int print_bin_file(FILE *f);

#endif
