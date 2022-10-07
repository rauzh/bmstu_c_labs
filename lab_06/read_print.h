#ifndef LAB_6_READPRINT_H
#define LAB_6_READPRINT_H

void print_array(items_t items[], size_t items_count);
int read_to_array(FILE *f, items_t items[], size_t *i);
int print_specific_items(arg_t start, items_t items[], size_t items_count);

#endif //LAB_6_READPRINT_H
