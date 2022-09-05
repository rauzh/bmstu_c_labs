#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -c -g3 stud_del.c main.c sort_funcs.c stud_find.c io_funcs.c main_branches.c  -lm
gcc stud_del.o io_funcs.o stud_find.o main.o sort_funcs.o main_branches.o -o app.exe
