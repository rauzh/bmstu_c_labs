#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "snprintf.h"

int main(void)
{
    char koka[100];
    char koka_2[100];
    int i = my_snprintf(koka, 25, "e %s fer", "kek");
    int y = snprintf(koka_2, 25, "e %s fer", "kek");
    printf("%s\n%s\n", koka, koka_2);
    printf("%d    %d     %d\n", i, y, strcmp(koka, koka_2));

    return EXIT_SUCCESS;
}
