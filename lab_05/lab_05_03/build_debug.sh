#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -c -g3 main.c funcs_sort.c funcs_io.c main_branches.c -lm
gcc main_branches.o funcs_io.o funcs_sort.o main.o -o app.exe
