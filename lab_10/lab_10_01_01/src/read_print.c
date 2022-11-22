#define _POSIX_C_SOURCE 200809L

#include "read_print.h"
#include "node_funcs.h"
#include "defs.h"

void list_fprintf(FILE *f, node_t *head)
{
	data_t *tmp;
	while (head != NULL)
	{
		tmp = head->data;
		fprintf(f, "%d %s", tmp->aim_type, tmp->name);
		head = head->next;
	}
}

int read_to_list(FILE *f, node_t **head_1, node_t **head_2, size_t *i, size_t *j)
{
	data_t aim_data;
	size_t len = 0;
	char chapa;

	while (fscanf(f, "%c %d", &chapa, &(aim_data.aim_type)) == 2)
	{
		aim_data.name = NULL;
		if (getline(&aim_data.name, &len, f) == -1)
			return INVALID_INPUT;

		node_t *node = node_create(&aim_data);
		if (chapa == '$')
		{
			add_to_head(head_1, node);
			(*i)++;
		}
		else
		{
			add_to_head(head_2, node);
			(*j)++;
		}
		
		free(aim_data.name);
	}

	return EXIT_SUCCESS;
}


