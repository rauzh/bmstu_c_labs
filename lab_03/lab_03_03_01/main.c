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

#define SWAP(x, y) { int SWAP = x; x = y; y = SWAP; }

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
        return LIMITS_ERROR;	    
    }

    return EXIT_SUCCESS;
}

void print_array(const int *arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
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

int max_of_row(int *arr, const size_t n)
{
    int max = arr[0];

    for (size_t i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];    		

    return max;
}

void selection_sort_matrix_rows(int a[][MAX_LEN_COL_ROW], const size_t n, const size_t m)
{
    size_t i, j, max_idx; 

    for (i = 0; i < n; i++)
    {
        max_idx = i;

        for (j = i + 1; j < n; j++)
            if (max_of_row(a[j], m) > max_of_row(a[max_idx], m))
                max_idx = j;	

        for (size_t k = 0; k < m; k++)
            SWAP(a[i][k], a[max_idx][k]);   
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

    selection_sort_matrix_rows(a, n, m);
 
    print_matrix(a, n, m);

    return EXIT_SUCCESS;
}
