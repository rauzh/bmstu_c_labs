#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FAIL -1
#define EPS 1e-9


/**
 * @brief 'super' function for inputting data till the negative 
 * ivalue comes and then for counting sum of given polynom
 * @return res Sum value
 */ 
double input_and_expression(void)
{
    int check, i = 0;
    double sum = 0, x = 1;

    printf("Input x: ");
    check = scanf("%lf", &x);

    if (check != 1 || x < 0)
    {
        fprintf(stderr, "You should have input float x > 0.");
        return FAIL;
    }

    while (x >= 0)
    {
        i++;	    
        sum += sqrt(x / i);

        printf("Input x: ");
        check = scanf("%lf", &x);

        if (check != 1)
        {
            fprintf(stderr, "You should have input float x.");
            return FAIL;
        }    
    }	    

    double res;
    res = sin(sum);
    return res;
}


int main(void)
{  
    double res = input_and_expression();

    if (fabs(res - FAIL) < EPS)
        return EXIT_FAILURE;

    printf("g(x) = %lf\n", res);
 
    return EXIT_SUCCESS;
}

