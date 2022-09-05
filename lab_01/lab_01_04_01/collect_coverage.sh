#!/bin/bash

./clean.sh

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -O0 -fprofile-arcs -ftest-coverage -o app.exe main.c -lm 

for file in func_tests/data/pos_*_in.txt func_tests/data/neg_*_in.txt; do
    if [ -f "$file" ]; then
        ./app.exe < "$file" > /dev/null
    fi 
done

gcov -abf main.c

