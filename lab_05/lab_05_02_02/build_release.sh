#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -c -O3 main.c get_sum_count_avg.c get_disp.c -lm
gcc main.o get_sum_count_avg.o get_disp.o -o app.exe
