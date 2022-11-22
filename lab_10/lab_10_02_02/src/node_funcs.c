#define _POSIX_C_SOURCE 200809L

#include "node_funcs.h"
#include "defs.h"
#include <string.h>

node_t *node_create(int ratio)
{
	node_t *node = malloc(sizeof(node_t));
	if (node == NULL)
		return node;

	node->ratio = ratio;
	node->next = NULL;
	
	return node;
}

void free_list(node_t *head)
{
	node_t *tmp;
	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void add_to_tail(node_t **head, node_t *node)
{
	node_t *tmp = *head;
	if (*head == NULL)
	{
		*head = node;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
  
	tmp->next = node;
	
	return;
}
