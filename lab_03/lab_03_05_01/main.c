#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_LEN_COL_ROW 10
#define SCANF_ONE_EL_SUCCESS 1
#define SHIFT_LEN 3

#define INVALID_INPUT -1
#define LIMIT_ERROR -2
#define EXIT_INVALID_INPUT_N 117
#define EXIT_INVALID_INPUT_M 118
#define EXIT_INVALID_INPUT_EL 119
#define EXIT_NO_ELS_TO_OPERATE_WITH 116

typedef enum
{
    FALSE,
    TRUE = 1
} bool;

int input_matrix(int a[][MAX_LEN_COL_ROW], const size_t n, const size_t m)
{
    int rc;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)	    
        {
            printf("Input elem: ");
            rc = scanf("%d", &a[i][j]);
            if (rc != SCANF_ONE_EL_SUCCESS)
            {
                fprintf(stderr, "Invalid input.\n");		    
                return INVALID_INPUT;
            }		
        }

    return EXIT_SUCCESS;
}

int input_size(size_t *n)
{
    int rc;
    rc = scanf("%zu", n);
	    
    if (rc != SCANF_ONE_EL_SUCCESS)
    {
        fprintf(stderr, "Invalid input.\n");
        return INVALID_INPUT;
    }

    if (*n > MAX_LEN_COL_ROW || *n <= 0)
    {
        fprintf(stderr, "Invalid input. You should have input one..ten integer.\n");
        return LIMIT_ERROR;	    
    }

    return EXIT_SUCCESS;
}

void print_array(const int *arr, const size_t m)
{
    for (size_t i = 0; i < m; i++)
        printf("%d ", arr[i]);
}

void print_matrix(int a[][MAX_LEN_COL_ROW], const size_t n, const size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        print_array(a[i], m);
        printf("\n");
    }  
}

bool sum_of_digits_more_ten(int num)
{
    int sum = 0;
    num = abs(num);
    
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }	    

    return sum > 10;
}

// Get elements with sum of digits greater than ten
int get_valid_elems(int mtrx[][MAX_LEN_COL_ROW], int **arr, const size_t n, const size_t m)
{
    size_t count = 0;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (sum_of_digits_more_ten(mtrx[i][j]) == TRUE)
            {
                arr[count] = &mtrx[i][j];
                count++;
            }		

    return count;
}

void shift_left(int **arr, size_t count)
{
    int tmp;

    for (int i = 0; i < SHIFT_LEN; i++)
    {
        tmp = *arr[0];
        for (size_t j = 0; j < count - 1; j++)
            *arr[j] = *arr[j + 1];		

        *arr[count - 1] = tmp;
    }	    
}

int main(void)
{
    size_t n, m;
    int rc;

    printf("Input num of rows: ");
    rc = input_size(&n);

    if (rc != EXIT_SUCCESS)
        return EXIT_INVALID_INPUT_N;	    

    printf("Input num of columns: ");
    rc = input_size(&m);

    if (rc != EXIT_SUCCESS)
        return EXIT_INVALID_INPUT_M;	    
   
    int a[MAX_LEN_COL_ROW][MAX_LEN_COL_ROW];

    rc = input_matrix(a, n, m);

    if (rc != EXIT_SUCCESS)
        return EXIT_INVALID_INPUT_EL;	    

    int *arr[MAX_LEN_COL_ROW * MAX_LEN_COL_ROW];

    size_t count = get_valid_elems(a, arr, n, m);

    if (count == 0)
    {
        fprintf(stderr, "No elements with sum of digits more than ten.\n");
        return EXIT_NO_ELS_TO_OPERATE_WITH;
    }	    

    shift_left(arr, count);
 
    print_matrix(a, n, m);

    return EXIT_SUCCESS;
}
