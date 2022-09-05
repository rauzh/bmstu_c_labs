#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -c -g3 main.c process.c -lm
gcc main.o process.o -o app.exe
