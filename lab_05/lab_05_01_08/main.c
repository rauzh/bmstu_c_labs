#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "process.h"
#include "defs.h"
#include "types.h"

int main(void)
{
	int rc;

	rc = process(stdin);
	
	return rc;
}
