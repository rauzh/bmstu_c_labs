#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define NUM_OF_APS_ONE_FLOOR 4
#define NUM_OF_FLOORS 9


int main(void)
{
    int n, check;


    printf("Input apartment number: ");
    check = scanf("%d", &n);

    if (check != 1 || n == INT_MAX)
    {
        fprintf(stderr, "Invalid input\n");
        return EXIT_FAILURE;
    }	    

    int gate, floor;
    gate = (n - 1) / (NUM_OF_FLOORS * NUM_OF_APS_ONE_FLOOR) + 1;
    floor = ((n - (gate - 1) * NUM_OF_FLOORS * NUM_OF_APS_ONE_FLOOR) - 1) / NUM_OF_APS_ONE_FLOOR + 1;

    printf("Gate: %d\nFloor: %d\n", gate, floor);

    return EXIT_SUCCESS;
}

