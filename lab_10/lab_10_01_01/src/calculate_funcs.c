

#include "defs.h"
#include "types.h"
#include "node_funcs.h"
#include "calculate_funcs.h"
#include "read_print.h"

void insert_if_found(node_t **head_1, node_t **head_2)
{
	node_t *tmp = *head_2;
	while (tmp != NULL)
	{
		node_t *tmp_2 = find(*head_1, tmp->data, comparator_name);
		if (tmp_2 != NULL)
		{
			node_t *node = node_create(tmp->data);
			data_t *aim_data = node->data;
			(aim_data->aim_type)++;
			insert(head_1, node, tmp_2);
		}

		tmp = tmp->next;
	}
}

int get_most_dangerous_aims(const char *argv[])
{
	node_t *head_1 = NULL, *head_2 = NULL;
	size_t len_1 = 0, len_2 = 0;
	FILE *f = fopen(argv[1], "r");
	
	int rc = read_to_list(f, &head_1, &head_2, &len_1, &len_2);
	if (rc != EXIT_SUCCESS)
		return rc;

	insert_if_found(&head_1, &head_2);

	remove_duplicates(&head_1, comparator_name);

	node_t *head_res = sort(head_1, comparator_type);

	list_fprintf(stdout, head_res);

	free_list(head_1);
	free_list(head_2);
	fclose(f);	

	return EXIT_SUCCESS;
}
