#include <string.h>
#include <stdio.h>

#include "final_funcs.h"


int find_polynom_value(void)
{
	node_t *pol;
	int rc = input_polynom(&pol);
	if (rc != EXIT_SUCCESS)
		return rc;
	int x;
	rc = input_value(&x);
	if (rc != EXIT_SUCCESS)
	{
		free_list(pol);
		return rc;
	}

	int res;
	rc = calculate_value(pol, x, &res);
	free_list(pol);
	if (rc != EXIT_SUCCESS)
		return rc;

	printf("%d\n", res);

	return EXIT_SUCCESS;
}

int find_polynom_ddx(void)
{
	node_t *pol;
	int rc = input_polynom(&pol);
	if (rc != EXIT_SUCCESS)
		return rc;

	rc = calculate_print_ddx(pol);
	free_list(pol);
	if (rc != EXIT_SUCCESS)
		return rc;

	return EXIT_SUCCESS;
}

int find_polynoms_sum(void)
{
	node_t *pol_a;
	int rc = input_polynom(&pol_a);
	if (rc != EXIT_SUCCESS)
		return rc;

	node_t *pol_b;
	rc = input_polynom(&pol_b);
	if (rc != EXIT_SUCCESS)
	{
		free_list(pol_a);
		return rc;
	}

	rc = sum_polynoms(pol_a, pol_b);
	free_list(pol_a);
	free_list(pol_b);
	if (rc != EXIT_SUCCESS)
		return rc;

	return EXIT_SUCCESS;
}

int find_polynom_evenities(void)
{
	node_t *pol;
	int rc = input_polynom(&pol);
	if (rc != EXIT_SUCCESS)
		return rc;

	rc = print_ratio_even_degrees(pol);
	free_list(pol);
	if (rc != EXIT_SUCCESS)
		return rc;


	return EXIT_SUCCESS;
}

