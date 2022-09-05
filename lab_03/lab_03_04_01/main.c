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
#define EXIT_NOT_SQUARE 116

typedef enum
{
    FALSE,
    TRUE = 1
} bool;

int input_matrix(int a[][MAX_LEN_COL_ROW], const size_t n)
{
    int rc;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)	    
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
        return LIMITS_ERROR;	    
    }

    return EXIT_SUCCESS;
}

void print_array(const int *arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]); 
}

void print_matrix(int a[][MAX_LEN_COL_ROW], const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        print_array(a[i], n);
        printf("\n");
    }  
}

void flip_matrix_upper_triangle(int a[][MAX_LEN_COL_ROW], const size_t n)
{
    int tmp;	
    for (size_t i = 0; i < n / 2; i++)
        for (size_t j = 0; j < n; j++)
        {
            if (i <= j && i <= n - j - 1)
            {		    
                tmp = a[i][j];
                a[i][j] = a[n - i - 1][j];
                a[n - i - 1][j] = tmp;
            }
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
    
    if (n != m)
    {
        fprintf(stderr, "You should have input equal M and N.\n");
        return EXIT_NOT_SQUARE;
    }	    

    int a[MAX_LEN_COL_ROW][MAX_LEN_COL_ROW];

    rc = input_matrix(a, n);
    if (rc != EXIT_SUCCESS)
        return EXIT_INVALID_INPUT_EL;	    

    flip_matrix_upper_triangle(a, m);
 
    print_matrix(a, n);

    return EXIT_SUCCESS;
}
