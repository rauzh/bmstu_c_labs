#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
    float v1, v2;
    float t1, t2;
    float v, t;

    setbuf(stdout, NULL);

    printf("Input V1, T1, V2, T2: ");
    scanf("%f%f%f%f", &v1, &t1, &v2, &t2);

    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / (v1 + v2);

    if (isinf (t) || isnan (t))
    {
        fprintf(stderr, "Invalid input\n");
        return EXIT_FAILURE;
    }

    printf("Final volume (V) = %f\n", v);
    printf("Final temperature (T) = %f\n", t);

    return EXIT_SUCCESS;
}
