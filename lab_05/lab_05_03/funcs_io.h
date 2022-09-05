#ifndef __FIO_H__
#define __FIO_H__

int fill_bin_file(FILE *f, const char *const str_count);
int print_bin_file(FILE *f);
int get_size_file(FILE *f, size_t *size);

#endif
