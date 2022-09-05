#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define MAX_ARRAY_SIZE 10
#define NUM_OF_INPUT_ARRAY_SIZE 1

#define INVALID_INPUT -1
#define INVALID_INPUT_N -2
#define INVALID_INPUT_EL -3
#define EXIT_NO_PRIME -4


typedef enum
{
    TRUE = 1,
    FALSE = 0
} bool;


int64_t input_array(int64_t *a, const size_t n)
{
    int rc;

    for (size_t i = 0; i < n; i++)
    {
        printf("Input elem: ");
        rc = scanf("%ld", &a[i]);
        if (rc != 1)
            return INVALID_INPUT;
    }
    return EXIT_SUCCESS;
}


bool is_prime(int64_t num)
{
    int64_t tmp;

    if (num == 2)
        return TRUE;

    if (num <= 1)
        return FALSE;

    if (num % 2 == 0)
        return FALSE;

    tmp = num;

    for (int64_t i = 3; i * i <= tmp; i += 2)
    {
        if (num % i == 0)
            return FALSE;
        tmp -= i;
    }
    return TRUE;
}


size_t get_array_b(int64_t *a, const size_t n_a, int64_t *b)
{
    size_t n_b = 0;

    for (size_t i = 0; i < n_a; i++)
    {
        if (is_prime(a[i]) == TRUE)
        {          
            b[n_b] = a[i];
            n_b++;	    
        }                   
    }       

    return n_b;
}


void print_array(int64_t *arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%ld ", arr[i]);
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

    int64_t a[MAX_ARRAY_SIZE];

    if (input_array(a, n) == INVALID_INPUT)
    {
        fprintf(stderr, "Invalid input.\n");

        return INVALID_INPUT_EL;
    }

    int64_t b[MAX_ARRAY_SIZE];

    size_t n_b;
    n_b = get_array_b(a, n, b);

    if (n_b != 0)
    {       
        printf("Array b: ");        
        print_array(b, n_b);
        printf("\n");
    }          
    else
    {
        fprintf(stderr, "No prime elements.\n");
        return EXIT_NO_PRIME;
    }       
    
    return EXIT_SUCCESS;
}

