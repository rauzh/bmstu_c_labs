#!/bin/bash

exec 1>trash.txt
exec 2>trash.txt

real=$1;
expect=$2;

# Инициализация "чистых" файлов
if [[ -f clean_real.txt  ]]; then rm clean_real.txt; fi
touch clean_real.txt;
if [[ -f clean_expect.txt ]]; then rm clean_expect.txt; fi
touch clean_expect.txt;

# Получение "чистого" файла с числами
get_numbers () {
    grep -Eo "[+-]?[0-9][0-9]*.?[0-9]*" "$1" > "$2"
}

get_numbers "$real" clean_real.txt
get_numbers "$expect" clean_expect.txt

# Сравнение реальных и ожидаемых результатов из "чистых" файлов
if diff -w clean_real.txt clean_expect.txt; then
    exit 0
else
    exit 1
fi
