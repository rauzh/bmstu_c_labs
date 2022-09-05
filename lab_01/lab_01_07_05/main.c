#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_OF_INPUT 2

/**
 * @brief This function counts f(x)
 * @param x just x from outer program
 * @return f(x) value
 */

double f_x(double x)
{
    double f_x_res;

    f_x_res = 1.0 / (sqrt(1.0 - x * x));

    return f_x_res;
}

/**
 * @brief This function counts s(x)
 * @param x Just x from outer program
 * @param eps Epsilon for accuracy
 * @return s(x) value
 */

double s_x(double x, double eps)
{
    double s_x_res = 1;
    int i = 0;
    double elem = 1;
    
    while (elem >= eps)
    {
        i += 1;
        elem *= (x * x) * ((i * 2) - 1) / (i * 2);
        s_x_res += elem;
    }
    return s_x_res;
}

/**
 * @brief This function counts absolute error using given formula
 * @param s_x_res s(x) Result
 * @param f_x_res f(x) Result
 * @return absolute error value
 */

int absolute(double s_x_res, double f_x_res, double *absolute_res)
{
    *absolute_res = fabs(f_x_res - s_x_res);

    if (isnan (*absolute_res))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

/**
 * @brief This function counts relative error using given formula
 * @param s_x_res s(x) Result
 * @param f_x_res f(x) Result
 * @return relative error value
 */

int relative(double s_x_res, double f_x_res, double *relative_res)
{
    *relative_res = (fabs(f_x_res - s_x_res)) / fabs(f_x_res);

    if (isnan (*relative_res))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int main(void)
{
    double x, eps;

    int check;

    printf("Input x, eps: ");
    check = scanf("%lf%lf", &x, &eps);
    if (check != NUM_OF_INPUT)
    {
        fprintf(stderr, "You should have input (-1;1) x and (0;1] eps.\n");
        return EXIT_FAILURE;
    }

    if ((fabs(x) >= 1) || (eps > 1) || (eps <= 0))
    {
        fprintf(stderr, "You should have input (-1;1) x and (0;1] eps.\n");
        return EXIT_FAILURE; 
    }

    double f_x_res;
    f_x_res = f_x(x);

    double s_x_res;
    s_x_res = s_x(x, eps);

    double absolute_res = 0.0;
    if (absolute(s_x_res, f_x_res, &absolute_res) == EXIT_FAILURE)
    {
        fprintf(stderr, "Overflow!\n");
        return EXIT_FAILURE;
    }


    double relative_res = 0.0;
    if (relative(s_x_res, f_x_res, &relative_res) == EXIT_FAILURE)
    {
        fprintf(stderr, "Overflow!\n");
        return EXIT_FAILURE;
    }       

    printf("s(x): %f\nf(x): %f\n", s_x_res, f_x_res);
    printf("absolute error: %f\nrelative error: %f\n", absolute_res, relative_res);

    return EXIT_SUCCESS;
}
