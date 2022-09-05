#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "get_words.h"
#include "defs.h"
#include "types.h"
#include "write_file.h"

void write_file(pair_t res[M], size_t r, const char **const argv)
{
	FILE *g;

	g = fopen(argv[2], "w");
	
	for (size_t i = 0; i < r; i++)
		fprintf(g, "%s, %s\n", res[i].first_word, res[i].second_word);
	
	fclose(g);
}
