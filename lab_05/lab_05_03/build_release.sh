#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -c -O3 main.c funcs_sort.c funcs_io.c -lm
gcc funcs_io.o funcs_sort.o main.o -o app.exe
