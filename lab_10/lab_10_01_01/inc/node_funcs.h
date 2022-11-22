#ifndef __NODE_FUNCS_LAB_10__
#define __NODE_FUNCS_LAB_10__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../inc/types.h"

int comparator_name(const void *first, const void *second);
int comparator_type(const void *first, const void *second);

node_t *node_create(data_t *aim_data);
node_t *allocate_node();
void node_free(node_t *elem);
void add_to_head(node_t **head, node_t *aim);
data_t *copy_data(data_t *from);
void free_list(node_t *head);

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void *));
void *pop_front(node_t **head);
void *pop_back(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*));
void append(node_t **head_a, node_t **head_b);

node_t *sort(node_t *head, int (*comparator)(const void*, const void*));
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void*, const void*));

#endif // __NODE_FUNCS_LAB_10__
