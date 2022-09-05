#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "process.h"
#include "defs.h"
#include "types.h"

int write_answer(int count_lcl_max, int lcl_maxes_min_dist)
{
	if (count_lcl_max > 1)
	{
		fprintf(stdout, "%d\n", lcl_maxes_min_dist);
		return EXIT_SUCCESS;
	}
	else
		return NOT_ENOUGH_LCL_MAXES;
}

void local_max_finder(int num, int prev, bool *prev_bigger_prevprev, int *count_lcl_max, int *lcl_max_prev, int *lcl_maxes_min_dist, int *i)
{
	if (num < prev)
	{
		if (*prev_bigger_prevprev == TRUE)
		{
			(*count_lcl_max)++;
			if ((*count_lcl_max) == 1)
				*lcl_max_prev = *i;
			else
			{
				if ((*lcl_maxes_min_dist) >= (*i) - (*lcl_max_prev))
					*lcl_maxes_min_dist = (*i) - (*lcl_max_prev);

				*lcl_max_prev = *i;
			}
		}

		*prev_bigger_prevprev = FALSE;
	}
	else
	{
		if (num > prev)
			*prev_bigger_prevprev = TRUE;
	}
}

int process(FILE *f)
{
	int num, prev, i = 0;
	int lcl_maxes_min_dist = INT_MAX, lcl_max_prev = 0, count_lcl_max = 0;
	bool prev_bigger_prevprev = FALSE;
	int rc;

	rc = fscanf(f, "%d", &prev);
	if (rc != CORRECT_NUM)
		return INVALID_INPUT;

	while (fscanf(f, "%d", &num) == CORRECT_NUM)
	{
		i++;

		local_max_finder(num, prev, &prev_bigger_prevprev, &count_lcl_max, &lcl_max_prev, &lcl_maxes_min_dist, &i);

		prev = num;
	}

	rc = write_answer(count_lcl_max, lcl_maxes_min_dist);

	return rc;
}
