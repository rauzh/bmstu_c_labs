#define _POSIX_C_SOURCE 200809L

#include "read_print.h"
#include "node_funcs.h"
#include "defs.h"
#include "types.h"

void polynom_print(node_t *head)
{
	int tmp;
	while (head != NULL)
	{
		tmp = head->ratio;
		printf("%d ", tmp);
		head = head->next;
	}
}

int input_command(char *com, command_t *com_num)
{
	int rc = scanf("%s", com);
	if (rc == EOF)
		return INVALID_INPUT;
	if (strcmp(com, "val") == EQUAL)
	{
		*com_num = GET_VAL;
		return EXIT_SUCCESS;
	}
	if (strcmp(com, "ddx") == EQUAL)
	{
		*com_num = GET_DDX;
		return EXIT_SUCCESS;
	}
	if (strcmp(com, "sum") == EQUAL)
	{
		*com_num = GET_SUM;
		return EXIT_SUCCESS;
	}
	if (strcmp(com, "dvd") == EQUAL)
	{
		*com_num = GET_DVD;
		return EXIT_SUCCESS;
	}

	return INVALID_INPUT;
}

int input_value(int *value)
{
	int rc = scanf("%d", value);
	if (rc != CORRECT_COUNT)
		return INVALID_INPUT;

	return EXIT_SUCCESS;
}

int input_polynom(node_t **pol)
{
	int len = 0, ratio;

	int rc = scanf("%d", &len);
	if ((rc != CORRECT_COUNT) || (len <= 0))
		return INVALID_INPUT;

	node_t *tmp = NULL;
	*pol = tmp;

	for (; len > 0; len--)
	{
		rc = scanf("%d", &ratio);
		if (rc != CORRECT_COUNT)
		{
			free_list(tmp);
			free_list(*pol);
			return INVALID_INPUT;
		}

		tmp = node_create(ratio);
		if (tmp == NULL)
		{
			free_list(tmp);
			free_list(*pol);
			return MEMORY_ERROR;
		}
		add_to_tail(pol, tmp);
		tmp = tmp->next;
	}

	return EXIT_SUCCESS;
}


