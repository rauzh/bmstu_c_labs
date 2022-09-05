#!/bin/bash

exec 1>trash.txt;
exec 2>trash.txt;

real=$1;
expect=$2;

# Инициализация "чистых" файлов
if [[ -f clean_real.txt  ]]; then rm clean_real.txt; fi
touch clean_real.txt;
if [[ -f clean_expect.txt ]]; then rm clean_expect.txt; fi
touch clean_expect.txt;

# Получение "чистых" файлов с символами после подстроки "Result:"
get_result () {
    data=$(cat "$1");
    echo "${data#*Result:}" > "$2"
}

get_result "$real" clean_real.txt
get_result "$expect" clean_expect.txt

# Проверяем различия между реальными и ожидаемыми выходными данными
if diff -w clean_real.txt clean_expect.txt; then
    exit 0;
else
    exit 1;
fi
