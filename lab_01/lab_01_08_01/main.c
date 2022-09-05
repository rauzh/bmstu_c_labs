#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>


#define NUM_OF_INPUT 4

/**
 * @brief This function prints byte by its value
 * @param a Byte's value
 */

void bin_print(uint8_t a)
{
    uint8_t first_bit = 1;

    for (int i = CHAR_BIT - 1; i >= 0; i--)
        printf("%hhu", (a >> i) & first_bit);
}


int main(void)
{
    uint8_t byte1, byte2, byte3, byte4;
    int check;

    check = scanf("%hhu%hhu%hhu%hhu", &byte1, &byte2, &byte3, &byte4);
    if (check != NUM_OF_INPUT)
    {
        fprintf(stderr, "Error: Incorrect input.\n"); 
        return EXIT_FAILURE;
    }

    printf("Result: ");
    bin_print(byte1);
    bin_print(byte2);
    bin_print(byte3);
    bin_print(byte4);

    printf(" %hhu %hhu %hhu %hhu\n", byte1, byte2, byte3, byte4);


    return EXIT_SUCCESS;
}


