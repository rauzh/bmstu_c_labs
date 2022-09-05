#!/bin/bash

if [ -f  ./func_tests/scripts/clean_real.txt ]; then rm ./func_tests/scripts/clean_real.txt; fi
if [ -f  ./func_tests/scripts/clean_expect.txt ]; then rm ./func_tests/scripts/clean_expect.txt; fi
if [ -f  ./func_tests/scripts/out.txt ]; then rm ./func_tests/scripts/out.txt; fi
if [ -f  ./func_tests/scripts/trash.txt ]; then rm ./func_tests/scripts/trash.txt; fi
if [ -f  ./app.exe ]; then rm ./app.exe; fi
if [ -f  ./main.c.gcov ]; then rm ./main.c.gcov; fi
if [ -f  ./main.gcda ]; then rm *gcda; fi
if [ -f  ./main.gcno ]; then rm *gcno; fi
if [ -f  ./main.o ]; then rm *.o; fi
