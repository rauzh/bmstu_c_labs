#ifndef __SORT_H__
#define __SORT_H__

int get_number_by_pos(FILE *f, const size_t pos);
void put_number_by_pos(FILE *f, const size_t pos, const int num);
void selections_sort_bin_file(FILE *f, const size_t count);
int sort_bin_file(FILE *f);
void swap_in_file(FILE *f, size_t i, size_t pos, int min, int tmp);

#endif
