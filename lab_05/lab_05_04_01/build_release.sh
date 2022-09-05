#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -c -O3 stud_del.c main.c sort_funcs.c stud_find.c io_funcs.c -lm
gcc stud_del.o main.o sort_funcs.o stud_find.o io_funcs.o -o app.exe
