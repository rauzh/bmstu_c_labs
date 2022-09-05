#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define MAX_ARRAY_SIZE 20
#define MAX_ARRAY_INPUT 10
#define NUM_OF_INPUT_ARRAY_SIZE 1

#define FIB_0 0
#define FIB_1 1

#define INVALID_INPUT -1
#define INVALID_INPUT_N -2
#define INVALID_INPUT_EL -3


int input_array(int *arr, const size_t n)
{
    int rc;

    for (size_t i = 0; i < n; i++)
    {
        printf("Input elem: ");
        rc = scanf("%d", &arr[i]);
        if (rc != 1)
            return INVALID_INPUT;
    }
    return EXIT_SUCCESS;
}


void print_array(int *arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}


int get_fib(int num)
{
    if (num == 0)
        return FIB_0;

    if (num == 1)
        return FIB_1;

    int i = 0, fib_sum, fib_cur = 1, fib_next = 1;

    while (i < num - 2)
    {
        fib_sum = fib_cur + fib_next;
        fib_cur = fib_next;
        fib_next = fib_sum;
        i++;
    }	    

    return fib_next;
}


size_t insertion_in_arr_by_idx(int *arr, size_t n, const int elem_to_insert, const size_t idx_to_insert)
{
    size_t i = n;

    while (i > idx_to_insert)
    {
        arr[i] = arr[i - 1];
        i--;
    }	    

    arr[idx_to_insert] = elem_to_insert;

    return ++n;
}	


int edit_arr_with_condition(int *arr, size_t n)
{    
    int el, k = 0;
    size_t i = 0;    

    while (i < n)
    {
        if (arr[i] % 3 == 0)
        {	
            el = get_fib(k);
            n = insertion_in_arr_by_idx(arr, n, el, i + 1);
            k++;	    
            i++;	    
        }		
        i++;	
    }	    

    return n;
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

    if (input_array(a, n) == INVALID_INPUT)
    {
        fprintf(stderr, "Invalid input.\n");

        return INVALID_INPUT_EL;
    }

    n = edit_arr_with_condition(a, n);
    printf("Edited array with fibs: ");
    print_array(a, n);
    printf("\n");

    return EXIT_SUCCESS;
}
