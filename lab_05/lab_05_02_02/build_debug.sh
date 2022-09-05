#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -c -g3 main.c get_sum_count_avg.c get_disp.c -lm
gcc get_sum_count_avg.o get_disp.o main.o -o app.exe
