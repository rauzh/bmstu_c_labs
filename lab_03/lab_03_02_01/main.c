#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_LEN_COL_ROW 10
#define SCANF_ONE_EL_SUCCESS 1

#define INVALID_INPUT -1
#define LIMITS_ERROR -2
#define EXIT_INVALID_INPUT_N 117
#define EXIT_INVALID_INPUT_M 118
#define EXIT_INVALID_INPUT_EL 119

typedef enum
{
    FALSE,
    TRUE = 1
} bool;

int input_matrix(int mtrx[][MAX_LEN_COL_ROW], const size_t n, const size_t m)
{
    int rc;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)	    
        {
            printf("Input elem: ");
            rc = scanf("%d", &mtrx[i][j]);
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
        return LIMITS_ERROR;	    
    }

    return EXIT_SUCCESS;
}

void print_array(const int *arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]); 
}

void print_matrix(int mtrx[][MAX_LEN_COL_ROW], const size_t n, const size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        print_array(mtrx[i], m);
        printf("\n");
    }  
}

int sum_of_digits(int n)
{
    int sum = 0;

    int num = abs(n);

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void get_min_elem_by_sum_of_digits(int a[][MAX_LEN_COL_ROW], const size_t n, const size_t m, int *row, int *col)
{       
    int min = sum_of_digits(a[0][0]);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            if (sum_of_digits(a[i][j]) < min)
            {
                min = sum_of_digits(a[i][j]);
                *row = i;		
                *col = j;
            }	    
        }		
}

size_t del_row(int num, int a[][MAX_LEN_COL_ROW], size_t n, const size_t m)
{
    for (size_t k = num; k < n - 1; k++)
        for (size_t j = 0; j < m; j++)
            a[k][j] = a[k + 1][j];

    return (--n);
}

size_t del_column(int num, int a[][MAX_LEN_COL_ROW], const size_t n, size_t m)
{
    for (size_t j = num; j < m - 1; j++)
        for (size_t k = 0; k < n; k++)
            a[k][j] = a[k][j + 1];

    return (--m);
}

int main(void)
{
    size_t n, m;
    int rc;

    printf("Input num of rows: ");
    rc = input_size(&n);

    if (rc != EXIT_SUCCESS || n == 1)
        return EXIT_INVALID_INPUT_N;	    
    
    printf("Input num of columns: ");
    rc = input_size(&m);

    if (rc != EXIT_SUCCESS || m == 1)
        return EXIT_INVALID_INPUT_M;	    
    
    int a[MAX_LEN_COL_ROW][MAX_LEN_COL_ROW];

    rc = input_matrix(a, n, m);

    if (rc != EXIT_SUCCESS)
        return EXIT_INVALID_INPUT_EL;	    

    int row = 0, col = 0;
    get_min_elem_by_sum_of_digits(a, n, m, &row, &col);

    n = del_row(row, a, n, m);
    m = del_column(col, a, n, m);

    print_matrix(a, n, m);

    return EXIT_SUCCESS;
}
