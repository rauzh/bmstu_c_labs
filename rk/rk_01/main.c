#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>

/*
:set tabstop=4
:set shiftwidth=4
:set expandtab
*/


#define N 20
#define M 20


typedef enum
{
    FALSE,
    TRUE = 1
} bool;



void input_array(int *start_ptr, const int *end_ptr)
{
    while (start_ptr < end_ptr)
    {
        scanf("%d", start_ptr);
        start_ptr++;
    }
}


void print_array(int *start_ptr, const int *end_ptr)
{
    while (start_ptr < end_ptr)
    {
        printf("%d ", *start_ptr);
        start_ptr++;
    }
}


void del_el(int *start_ptr, int *end_ptr)
{
    while (start_ptr < end_ptr)
    {
        *start_ptr = *(start_ptr + 1);
        start_ptr++;
    }
}


size_t shift_l(int *start_ptr, int *end_ptr, int n)
{
    while (start_ptr < end_ptr - 2)
    {
        if (*start_ptr == *(start_ptr + 1) && *start_ptr == *(start_ptr + 2))     
        {
            *start_ptr = *start_ptr + *(start_ptr + 1);
            start_ptr++;
            int *cur = start_ptr;	    
            del_el(cur, end_ptr);
            n--;	    
            end_ptr--;
            start_ptr++;	    
        }		
        else if (*start_ptr == *(start_ptr + 1))
        {
            *start_ptr = (*start_ptr) * 2;
            start_ptr++;	    
            int *cur = start_ptr;	    
            del_el(cur, end_ptr);
            n--;	    
            end_ptr--;          
        }		
	else
            start_ptr++;
    }
    if (*start_ptr == *(start_ptr + 1))
        {
            *start_ptr = (*start_ptr) * 2;
            start_ptr++;	    
            n--;	    
            end_ptr--;          
        }
    return n;
}


size_t shift_r(int *start_ptr, int *end_ptr, int n)
{
    while (start_ptr < end_ptr - 2)
    {
        if (*start_ptr == *(start_ptr + 1) && *start_ptr == *(start_ptr + 2))     
        {
            start_ptr++;		
            *start_ptr = *start_ptr + *(start_ptr + 1);
            start_ptr++;	     
            int *cur = start_ptr;	    
            del_el(cur, end_ptr);
            n--;	    
            end_ptr--;	    
        }		
        else if (*start_ptr == *(start_ptr + 1))
        {
            *start_ptr = (*start_ptr) * 2;
            start_ptr++;	    
            int *cur = start_ptr;	    
            del_el(cur, end_ptr);
            n--;	    
            end_ptr--;          
        }		
	else
            start_ptr++; 	
    }
    if (*(end_ptr - 1) == *(end_ptr - 2))
        {
            *(end_ptr - 2) = *(end_ptr - 2) * 2; 
            n--;	    
            end_ptr--;          
        }

    return n;
}


size_t processing(int *s_pa, int *e_pa, int *s_po, const int *e_po, int n)
{
    size_t nn = n;	
    while(s_po < e_po)
    {
        if (*s_po < 0)
        {		
            nn = shift_l(s_pa, e_pa, nn);
            e_pa = s_pa + nn;	    
	}  	
        else
        {		
            nn = shift_r(s_pa, e_pa, nn);
            e_pa = s_pa + nn; 
        }	    	
        s_po++;
    }
    return nn;
}


int main(void)
{
    size_t n;
    int a[N];
    size_t m;
    int ops[M];

    printf("Input n: ");
    scanf("%zu", &n);

    printf("Input array a: ");
    input_array(a, a + n);

    printf("Input num of operations: ");
    scanf("%zu", &m);

    printf("Input operations: ");
    input_array(ops, ops + m);

    size_t nn = n;

    nn = processing(a, a + n, ops, ops + m, n);

    print_array(a, a + nn);
    printf("\n");

    return EXIT_SUCCESS;
}



