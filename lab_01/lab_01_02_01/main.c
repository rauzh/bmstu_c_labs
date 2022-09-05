#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
 
#define M_PI 3.14159265358979323846
#define FULL_ANGLE 180


// according to the task trapezoid exists => 0 < fi < pi / 2 
int main(void)
{
    double a, b;
    double fi;
 
    setbuf(stdout, NULL);
 
    printf("Input a, b, fi: ");
    scanf("%lf%lf%lf", &a, &b, &fi);       
 
    double s;
 
    s = (fabs((a - b) * (a / 4 + b / 4)) * tan((fi * M_PI) / FULL_ANGLE));
 
    if (isinf (s))
    {
        fprintf(stderr, "Invalid input (too big numbers)\n");
        return EXIT_FAILURE;
    }

    printf("Trapezoid area: %f\n", s);
 
    return EXIT_SUCCESS;
}
