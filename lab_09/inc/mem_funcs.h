#ifndef LAB_9_MEM_H
#define LAB_9_MEM_H

void free_struct_arr(items_t *items, size_t items_count);
int realloc_struct_arr(items_t **items, size_t *new_len, size_t *cur_len);
void struct_dynamic_swap(items_t *to, items_t *from, size_t count);

#endif //LAB_9_MEM_H
