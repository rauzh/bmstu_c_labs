#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-3
#define TRUE 1
#define FALSE 0
#define NUM_OF_COORDS 8


/**
 * @brief This function checks whether the point belongs to the segment
 * @param x Point's x
 * @param y Point's y
 * @param x_1 Segment's x1
 * @param y_1 Segment's y1
 * @param x_2 Segment's x2
 * @param y_2 Segment's y2
 * @return 1 (belongs) or 0 (not)
 */

int is_in_section(float x, float y, float x_1, float y_1, float x_2, float y_2)
{
    float s_x1_x2, s_x1_x, s_x2_x;

    s_x1_x2 = sqrtf((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1));
    s_x1_x = sqrtf((x - x_1) * (x - x_1) + (y - y_1) * (y - y_1));
    s_x2_x = sqrtf((x - x_2) * (x - x_2) + (y - y_2) * (y - y_2));

    if (fabs((s_x1_x + s_x2_x) - s_x1_x2) < EPS)
        return TRUE;
    return FALSE;
}


int main(void)
{
    float x, y, x1, y1, x2, y2, x3, y3, x4, y4;
    
    printf("Input xp, yp, xq, yq, xr, yr, xs, ys: ");

    if (scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != NUM_OF_COORDS)
    {
        fprintf(stderr, "Input error\n");
        return EXIT_FAILURE;
    }

    float a1, a2, b1, b2, c1, c2;

    a1 = y1 - y2;
    b1 = x2 - x1;
    c1 = x1 * y2 - x2 * y1;
    a2 = y3 - y4;
    b2 = x4 - x3;
    c2 = x3 * y4 - x4 * y3;


    if ((fabs(a1) < EPS) && (fabs(b1) < EPS))
    {
        fprintf(stderr, "You should have input segments, not points\n");
        return EXIT_FAILURE;
    }

    if ((fabs(a2) < EPS) && (fabs(b2) < EPS))
    {
        fprintf(stderr, "You should have input segments, not points\n");
        return EXIT_FAILURE;
    }

    if ((is_in_section(x1, y1, x3, y3, x4, y4) &&
        is_in_section(x2, y2, x3, y3, x4, y4)) ||
        (is_in_section(x3, y3, x1, y1, x2, y2) &&
        is_in_section(x4, y4, x1, y1, x2, y2)))
    {
        printf("%d", TRUE);
        return EXIT_SUCCESS;
    }
    if ((is_in_section(x1, y1, x3, y3, x4, y4) ||
        is_in_section(x2, y2, x3, y3, x4, y4)) ||
        (is_in_section(x3, y3, x1, y1, x2, y2) ||
        is_in_section(x4, y4, x1, y1, x2, y2)))
    {
        printf("%d", FALSE);
        return EXIT_SUCCESS;
    }

  
    if (fabs(a1 / a2 - b1 / b2) < EPS) 
    {
        printf("%d", FALSE);
        return EXIT_SUCCESS;
    }

    float det = a1 * b2 - a2 * b1;
    x = (b1 * c2 - b2 * c1) / det;
    y = (a2 * c1 - a1 * c2) / det;
    
    int res1, res2;

    res1 = is_in_section(x, y, x1, y1, x2, y2);
    res2 = is_in_section(x, y, x3, y3, x4, y4);

    if ((res1 == TRUE) && (res2 == TRUE))
        printf("%d", TRUE);
    else
        printf("%d", FALSE);

    return EXIT_SUCCESS;
}


