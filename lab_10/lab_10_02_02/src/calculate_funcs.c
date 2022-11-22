#include "calculate_funcs.h"

int calculate_value(node_t *pol, int x, int *res)
{
	if (pol == NULL)
		return MEMORY_ERROR;

	int len = 0;
	*res = 0;
	node_t *tmp = pol;

	for (; tmp != NULL; tmp = tmp->next)
		len++;
	len--;

	for (; pol != NULL; pol = pol->next)
	{
		*res += ((int) pow(x, len)) * pol->ratio;
		len--;
	}

	return EXIT_SUCCESS;
}

int calculate_print_ddx(node_t *pol)
{
	if (pol == NULL)
		return MEMORY_ERROR;

	int len = 0;
	node_t *tmp = pol;
	for (; tmp != NULL; tmp = tmp->next)
		len++;
	len--;

	for (; pol != NULL; pol = pol->next)
	{
		if (len == 0)
		{
			printf("L\n");
			return EXIT_SUCCESS;
		}

		printf("%d ", len * pol->ratio); 
		len--;
	}

	return EXIT_SUCCESS;
}

int sum_polynoms(node_t *pol_a, node_t *pol_b)
{
	if ((pol_a == NULL) || (pol_b == NULL))
		return MEMORY_ERROR;

	int len_a = 0;
	node_t *tmp = pol_a;
	for (; tmp != NULL; tmp = tmp->next)
		len_a++;
	len_a--;

	int len_b = 0;
	tmp = pol_b;
	for (; tmp != NULL; tmp = tmp->next)
		len_b++;
	len_b--;

	int len_general = len_b > len_a ? len_a : len_b;
	if (len_b > len_general)
		for (int i = 0; i < (len_b - len_general); i++)
		{
			printf("%d ", pol_b->ratio);
			pol_b = pol_b->next;
		}
	if (len_a > len_general)
		for (int i = 0; i < (len_a - len_general); i++)
		{
			printf("%d ", pol_a->ratio);
			pol_a = pol_a->next;
		}

	while (pol_a != NULL)
	{
		printf("%d ", pol_a->ratio + pol_b->ratio);

		pol_a = pol_a->next;
		pol_b = pol_b->next;
	}

	printf("L\n");

	return EXIT_SUCCESS;
}

int print_ratio_even_degrees(node_t *pol)
{
	if (pol == NULL)
		return MEMORY_ERROR;

	int len = 0;
	node_t *tmp = pol;
	for (; tmp != NULL; tmp = tmp->next)
		len++;
	len--;

	tmp = pol;
	for (int i = len; tmp != NULL; i--, tmp = tmp->next)
		if (i % 2 == 0)
			printf("%d ", tmp->ratio);
	puts("L");

	for (int i = len; pol != NULL; i--, pol = pol->next)
		if (i % 2 != 0)
			printf("%d ", pol->ratio);
	puts("L");

	return EXIT_SUCCESS;
}
