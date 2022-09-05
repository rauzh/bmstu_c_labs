#ifndef __DEL_H__
#define __DEL_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

double get_average_by_pos(FILE *f, const size_t pos);
double get_average_of_all_studs(FILE *f, const size_t count);
void del_stud_by_pos(FILE *f, const size_t pos, const size_t count);
void delete_studs_w_min_average(FILE *f, size_t *count, const double average_of_all_studs);
int stud_del(FILE *f);

#endif
