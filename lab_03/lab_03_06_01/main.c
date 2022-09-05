#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_LEN_COL_ROW 10
#define SCANF_ONE_EL_SUCCESS 1

#define INVALID_INPUT -1
#define LIMITS_ERROR -2
#define EXIT_INVALID_INPUT_N 117
#define EXIT_INVALID_INPUT_M 118
#define EXIT_NOT_SQUARE 119

typedef enum
{
    FALSE,
    TRUE = 1
} bool;

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

void spiral_fill(int a[][MAX_LEN_COL_ROW], const size_t n, const size_t m)
{
    size_t i_start = 0, i_end = 0, j_start = 0, j_end = 0;
    size_t k = 1, i = 0, j = 0;

    while (k <= n * m)
    {
        a[i][j] = k;
        if (i == i_start && j < m - j_end - 1)
            j++;
        else if (j == m - j_end - 1 && i < n - i_end - 1)
            i++;
        else if (i == n - i_end - 1 && j > j_start)
            j--;
        else
            i--;

        if ((i == i_start + 1) && (j == j_start) && (j_start != m - j_end - 1))
        {
            i_start++;
            i_end++;
            j_start++;
            j_end++;  
        }		
        k++; 
    }    
}

int main(void)
{
    size_t n, m;
    int rc;

    printf("Input num of lines: ");
    rc = input_size(&n);

    if (rc != EXIT_SUCCESS)
        return EXIT_INVALID_INPUT_N;	    
    
    printf("Input num of columns: ");
    rc = input_size(&m);

    if (rc != EXIT_SUCCESS)
        return EXIT_INVALID_INPUT_M;	    

    if (m != n)
    {
        fprintf(stderr, "You should have input equal num of rows & columns.\n");
        return EXIT_NOT_SQUARE;	    
    }	    

    int a[MAX_LEN_COL_ROW][MAX_LEN_COL_ROW];

    spiral_fill(a, n, m);
 
    print_matrix(a, n, m);

    return EXIT_SUCCESS;
}
