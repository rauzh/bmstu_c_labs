#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "get_words.h"
#include "defs.h"
#include "types.h"
#include "write_file.h"

int main(int argc, const char **const argv)
{
	char words[M][N];
	size_t n;
	int rc = 0;
	
	pair_t res[M];
	pair_t pair;
	
	rc = get_words(words, argv, &n);

	if (rc != EXIT_SUCCESS)
		return EXIT_FAILURE;
    
    size_t r = 0;
    
    for (size_t i = 0; i <= n - 1; i++)
    {
    	for (size_t j = i + 1; j <= n; j++)
    	{
    		int k = 0;
    		for (size_t q = 0; q < N - 1; q++)
    		{
    			if (words[i][q] != words[j][q])
    			{
    				k++;
    			}
    		}
    		if (k == 1)
    		{
    			strcpy(pair.first_word, words[i]);
    			strcpy(pair.second_word, words[j]);
    		    
    		    res[r] = pair;
    		    
    		    r++;
    		}
    		k = 0;
    	}
    }
    
   	write_file(res, r, argv);
   	
	return EXIT_SUCCESS;
}

