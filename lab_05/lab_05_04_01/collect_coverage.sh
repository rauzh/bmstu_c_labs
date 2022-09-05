#!/bin/bash

./clean.sh

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fprofile-arcs -ftest-coverage -o app.exe stud_del.c main.c sort_funcs.c stud_find.c io_funcs.c -lm 

for file in func_tests/data/pos_*_in.txt func_tests/data/neg_*_in.txt; do
    if [ -f "$file" ]; then
        ./app.exe "$file" > /dev/null
    fi
done

mv app-main.gcno main.gcno
mv app-main.gcda main.gcda

gcov -abf main.c