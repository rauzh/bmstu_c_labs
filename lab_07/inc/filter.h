#ifndef LAB_07_01_03_FILTER_H
#define LAB_07_01_03_FILTER_H

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
float arr_mean(const int *pb_src, const int *pe_src);
int count_via_mean(const int *pb_src, const int *pe_src, size_t *new_count, float mean);

#endif //LAB_07_01_03_FILTER_H
