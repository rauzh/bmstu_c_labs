#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define MAX_ARRAY_SIZE 10
#define NUM_OF_INPUT_ARRAY_SIZE 1

#define INVALID_INPUT -1
#define END_BY_LIMIT 100
#define INVALID_INPUT_N -2
#define INVALID_INPUT_EL -3



int input_array_until_non_digit(int *a, size_t *n)
{
    int rc;

    for (size_t i = 0; i < MAX_ARRAY_SIZE; i++)
    {   
        printf("Input elem: ");
        rc = scanf("%d", &a[i]);

        if (rc != 1 && i > 0)
            return EXIT_SUCCESS;

        if (rc != 1 && i == 0)
            return EXIT_FAILURE;

        (*n)++;
    }

    int check_end;

    if (scanf("%d", &check_end) == 1)
        return END_BY_LIMIT;

    return EXIT_SUCCESS;
}


void print_array(int *arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}


void swap(int *xp, int *yp)
{
    int temp = *xp;

    *xp = *yp;
    *yp = temp;
}

void selection_sort(int *arr, const size_t n)
{
    size_t i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

int main(void)
{
    int a[MAX_ARRAY_SIZE];

    size_t n = 0;
    int error = input_array_until_non_digit(a, &n);

    if (error == EXIT_FAILURE)
    {
        fprintf(stderr, "Invalid input.\n");

        return INVALID_INPUT_EL;
    }

    selection_sort(a, n);

    printf("Sorted array: ");
    print_array(a, n);
    printf("\n");

    return error;
}
