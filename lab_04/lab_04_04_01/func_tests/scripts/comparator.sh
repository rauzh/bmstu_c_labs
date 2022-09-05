#!/bin/bash

exec 1>trash.txt
exec 2>trash.txt

real=$1;
expect=$2;

# Сравнение реальных и ожидаемых результатов из файлов 
if diff $real $expect; then
    exit 0
else
    exit 1
fi
