/*
    1. Реализовать функцию заполнения массива числами Фибоначчи.
    2. Реализовать функцию, которая из одного массива помещает во второй массив
        первое вхождение каждого элемента первого массива.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "lib.h"

void fibonacci_arr_fill(int *arr, int n)
{
    if (n < 1)
        return;
    int fib_1 = 1, fib_2 = 1, fib_sum;
    for (int k = 0; k < n; k++)
    {
        fib_1 = 1;
        fib_2 = 1;
        for (int i = 0; i < k - 2; i++)
        {
            fib_sum = fib_1 + fib_2;
            fib_1 = fib_2;
            fib_2 = fib_sum;
        }
        arr[k] = k == 0 ? 0 : fib_2;
    }
}

int get_unique_arr(int *arr, int n, int *res_arr, int res_n)
{
    int count = 0, unique_count = 0;

    for (int i = 0; i < n; i++)
    {
        unique_count = 0;
        for (int j = 0; j < i; j++)
            if (arr[i] == arr[j])
                unique_count++;

        if (unique_count == 0)
        {
            if (res_n)
                res_arr[count] = arr[i];
            count++;
        }
    }

    res_n = count;

    return res_n;
}
