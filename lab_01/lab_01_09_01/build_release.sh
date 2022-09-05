#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -c -O3 main.c -lm
gcc main.o -o app.exe

