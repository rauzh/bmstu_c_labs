#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX_ARRAY_SIZE 10
#define NUM_OF_INPUT_ARRAY_SIZE 1

#define INVALID_INPUT -1
#define INVALID_INPUT_N -2
#define INVALID_INPUT_EL -3
#define EXIT_NO_ODDS -4


typedef enum
{
    TRUE = 1,
    FALSE = 0
} bool;


int input_array(int *start_ptr, const int *end_ptr)
{
    int i = 0, rc;

    while (start_ptr + i < end_ptr)
    {
        printf("Input elem: ");
        rc = scanf("%d", start_ptr + i);
        if (rc != 1)
        {
            return INVALID_INPUT;
        }
        i++;
    }
    return EXIT_SUCCESS;
}


bool check_odds(const int *start_ptr, const int *end_ptr)
{
    int i = 0;
    bool check = FALSE;

    while (start_ptr + i < end_ptr)
    {
        if (*(start_ptr + i) % 2 != 0)
        {
            check = TRUE;
            break;
        }
        i++;	
    }
    
    return check;
}


int get_product_of_odd_elems(const int *start_ptr, const int *end_ptr)
{
    int product = 1, i = 0;

    while (start_ptr + i < end_ptr)
    {
        if (*(start_ptr + i) % 2 != 0)
        {		
            product *= *(start_ptr + i);
        }
        i++;      	
    }

    return product;
}


int main(void)
{
    size_t n;
    printf("Input num of elements: ");

    int rc;
    rc = scanf("%zu", &n);

    if (rc != NUM_OF_INPUT_ARRAY_SIZE)
    {
        fprintf(stderr, "Invalid input.\n");

        return INVALID_INPUT_N;
    }

    if (n > MAX_ARRAY_SIZE || n <= 0)
    {
        fprintf(stderr, "Invalid array size.\n");
    
        return INVALID_INPUT_N;
    }

    int a[MAX_ARRAY_SIZE];

    if (input_array(a, a + n) == INVALID_INPUT)
    {
        fprintf(stderr, "Invalid input.\n");

        return INVALID_INPUT_EL;
    }

    if (check_odds(a, a + n) == TRUE)
    {
        int product;
        product = get_product_of_odd_elems(a, a + n);
        printf("Product of odd elements: %d\n", product);
    }
    else
    {
        fprintf(stderr, "No odd elements.\n");

        return EXIT_NO_ODDS;	
    }     

    return EXIT_SUCCESS;
}

