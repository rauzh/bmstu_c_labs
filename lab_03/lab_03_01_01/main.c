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

void get_bool_arr_of_polyndroms(int mtrx[][MAX_LEN_COL_ROW], const size_t n, const size_t m, int *arr)
{
    bool check;
    for (size_t i = 0; i < n; i++)
    {
        check = TRUE;   
        for (size_t j = 0; j < m / 2; j++)
        {
            if (mtrx[i][j] != mtrx[i][m - 1 - j])
                check = FALSE;
        }

        arr[i] = check == TRUE;
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

    int b[MAX_LEN_COL_ROW] = { FALSE };

    get_bool_arr_of_polyndroms(a, n, m, b);
 
    print_array(b, n);

    return EXIT_SUCCESS;
}
