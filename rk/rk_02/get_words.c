#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "get_words.h"

int get_words(char words[][N], const char **const argv, size_t *n)
{
	FILE *f;
	f = fopen(argv[1], "r");

	*n = 0;

    while ((fscanf(f, "%s", words[*n]) == 1) && (*n <= M))
    {
        if (strlen(words[*n]) > N)
            return EXIT_FAILURE;
        (*n)++;
    }

    if (!(*n))
        return EXIT_FAILURE;

    if (*n == (M + 1))
        return EXIT_FAILURE;
        
    fclose(f);
	
	return EXIT_SUCCESS;
}
