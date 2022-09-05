#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define GET_LEN_OF_NUM(num) \
        while (num > 0) {num = num / 10; len++;}

/** @brief Function for counting power og long int 
*@param power Needed power
*@return num in needed power
*/

long int get_num_in_power(long int num, long int power)
{
    long int base = num;

    if (power == 0)
        return 1;

    while (power > 1)
    {
        num *= base;   
        power--;
    }
    return num;
}

/**
*@brief Function for getting number from digit and printing it
*@param n Digit
*/

void print_digit_by_nums(long int n)
{
    long int dig;
    long int len = 0, num = n;

    GET_LEN_OF_NUM(num);

    long int ten_pow;

    while (len > 0)
    {
        ten_pow = get_num_in_power(10, len - 1);
        dig = n / ten_pow;

        printf("%ld", dig);

        n = n % ten_pow;
        len--;
    }
}

int main(void)
{
    long int n;
    long int rc;

    printf("Input natural n: ");

    rc = scanf("%ld", &n);


    if (rc != 1)
    {
        fprintf(stderr, "You should have input natural number.\n");
        return EXIT_FAILURE;
    }
    if ((n <= 0) | (n == LLONG_MAX))
    {
        fprintf(stderr, "You should have input natural number.\n");
        return EXIT_FAILURE;
    }
    
    print_digit_by_nums(n);
    printf("\n");

    return EXIT_SUCCESS;
}

