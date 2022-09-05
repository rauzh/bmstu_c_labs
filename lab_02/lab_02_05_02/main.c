#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX_ARRAY_SIZE 10
#define NUM_OF_INPUT_ARRAY_SIZE 1

#define INVALID_INPUT -1
#define INVALID_INPUT_N -2
#define INVALID_INPUT_EL -3


int input_array(int *start_ptr, const int *end_ptr)
{
    int rc;

    while (start_ptr < end_ptr)
    {
        printf("Input elem: ");
        rc = scanf("%d", start_ptr);
        if (rc != 1)
            return INVALID_INPUT;

        start_ptr++;
    }
    return EXIT_SUCCESS;
}


int *get_negative_idx(int *start_ptr, const int *end_ptr)
{		
    while (start_ptr < end_ptr)
    {
        if (*start_ptr < 0)
            return start_ptr;

        start_ptr++;	
    }    
    
    return --start_ptr;
}


int get_factorial_till_idx(int *start_ptr, const int *end_ptr)
{
    int res = 1;

    while (start_ptr <= end_ptr)
    {
        res *= *start_ptr;
        start_ptr++;	
    }

    return res;
}


int count_sum(int *start_ptr, const int *end_ptr)
{
    int sum = 0;
    int *cur = start_ptr;

    while (cur <= end_ptr)
    {
        sum += get_factorial_till_idx(start_ptr, cur);
        cur++;
    }	    

    return sum;
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

    int *end_ptr = get_negative_idx(a, a + n);
    int sum = count_sum(a, end_ptr);

    printf("Sum = %d\n", sum);

    return EXIT_SUCCESS;
}

