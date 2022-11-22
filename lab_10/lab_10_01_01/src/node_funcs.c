#define _POSIX_C_SOURCE 200809L

#include "node_funcs.h"
#include "defs.h"
#include <string.h>

node_t *node_create(data_t *aim_data)
{
	node_t *node = malloc(sizeof(node_t));
	if (node == NULL)
		return node;

	data_t *tmp = copy_data(aim_data);
	if (tmp == NULL)
	{
		free(node);
		return NULL;
	}
	
	node->data = tmp;
	node->next = NULL;
	
	return node;
}

node_t *allocate_node()
{
	node_t *node = calloc(1, sizeof(node_t));

	return node;
}

data_t *copy_data(data_t *from)
{
	data_t *to = malloc(sizeof(data_t));
	if (to == NULL)
		return to;

	to->aim_type = from->aim_type;
	to->name = strdup(from->name);
	if (to->name == NULL)
	{
		free(to);
		return NULL;
	}

	return to;
}

void add_to_head(node_t **head, node_t *aim)
{
	aim->next = *head;
	*head = aim;
}

int comparator_name(const void *first, const void *second)
{
	const data_t *f_aim = first, *s_aim = second;
	return strcmp(f_aim->name, s_aim->name);
}

int comparator_type(const void *first, const void *second)
{
	const data_t *f_aim = first, *s_aim = second;
	return (int) -(f_aim->aim_type - s_aim->aim_type);
}

void free_list(node_t *head)
{
	node_t *tmp;
	while (head != NULL)
	{
		tmp = head->next;
		node_free(head);
		head = tmp;
	}
}

void node_free(node_t *node)
{
	data_t *tmp = node->data;
	free(tmp->name);
	free(node->data);
	free(node);
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void *))
{
	while (head != NULL)
	{
		if (comparator(head->data, data) == EQUAL)
			return head;

		head = head->next;
	}

	return NULL;
}

void *pop_front(node_t **head)
{
	if ((head == NULL) || (*head == NULL))
		return NULL;
	data_t *popped = (*head)->data;

	node_t *tmp = (*head);
	(*head) = (*head)->next;
	free(tmp);

	return popped;
}

void *pop_back(node_t **head)
{
	if ((head == NULL) || (*head == NULL))
		return NULL;

	data_t *popped;

	if ((*head)->next == NULL)
	{
		popped = (*head)->data;
		free(*head);
		*head = NULL;
		return popped;
	}

	node_t *tmp = (*head);

	while (tmp->next->next != NULL)
		tmp = tmp->next;

	popped = (tmp->next)->data;
	free(tmp->next);
	tmp->next = NULL;

	return popped;
}

void insert(node_t **head, node_t *elem, node_t *before)
{
	if ((head == NULL) || (*head == NULL))
		return;
	if ((elem == NULL) || (before == NULL))
		return;

	if (before == *head)
	{
		elem->next = *head;
		*head = elem;
		return;
	}

	node_t *tmp = *head;

	while ((tmp != NULL) && (tmp->next != before))
		tmp = tmp->next;

	if ((tmp != NULL) && (tmp->next == before)) 
	{
		tmp->next = elem;
		elem->next = before;
	}
}

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*))
{
	if ((head == NULL) || (*head == NULL) || ((*head)->next == NULL))
		return;

	node_t *tmp, *cur_node = *head;

	while (cur_node->next != NULL)
	{
		if (comparator(cur_node->data, cur_node->next->data) == EQUAL)
		{
			tmp = cur_node->next;
			cur_node->next = cur_node->next->next;
			free(tmp);
		}
		else
			cur_node = cur_node->next;
	}
}

void append(node_t **head_a, node_t **head_b)
{
	if (head_a == NULL)
		return;
	if ((head_b == NULL) || (*head_b == NULL))
		return;

	if (*head_a == NULL)
	{
		*head_a = *head_b;
		*head_b = NULL;
		return;
	}

	node_t *tmp = *head_a;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *head_b;

	*head_b = NULL;
}

node_t *sort(node_t *head, int (*comparator)(const void*, const void*))
{
	if ((head == NULL) || (head->next == NULL))
		return head;

	node_t *elem = head->next;
	node_t *new_head = head;

	new_head->next = NULL;

	for (node_t *cur_head; elem != NULL; elem = cur_head)
	{
		cur_head = elem->next;
		sorted_insert(&new_head, elem, comparator);
	}

	return new_head;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void*, const void*))
{
	if (head == NULL)
		return;

	if (*head == NULL)
	{
		if (element != NULL)
			*head = element;

		return;
	}

	if (comparator((*head)->data, element->data) > 0)
	{
		element->next = *head;
		*head = element;
		return;
	}

	node_t *cur = *head, *tmp;

	while (cur->next != NULL)
	{
		if (comparator(cur->next->data, element->data) > 0)
		{
			tmp = cur->next;
			cur->next = element;
			element->next = tmp;
			return;
		}
		cur = cur->next;
	}

	cur->next = element;
	element->next = NULL;
}
