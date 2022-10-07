#ifndef LAB_07_01_04_SORT_FUNCS_H
#define LAB_07_01_04_SORT_FUNCS_H

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
int compare(const int *, const int *);

#endif //LAB_07_01_04_SORT_FUNCS_H
