#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -c -g3 main.c -lm
gcc main.o -o app.exe

