#!/bin/bash

input=$1
app="../../app.exe"


# Проверка передачи файла с аргументами и его подключение
if [ $# -eq 2 ]; then
    args="../data/$2"
    app="$app $(cat "$args")"
fi

# Инициализация memo.txt
if [ -f memo.txt ]; then rm memo.txt; fi
touch out.txt

exec 1> trash.txt
exec 2> trash.txt

# Valgrind flag check & app execution with input data
if [ -z "$USE_VALGRIND" ]; then
    $app < "$input"
else
    valgrind -q --leak-check=full "$app" < "$input" 2> memo.txt
fi

exec_res=$?

# Проверка кода завершения 
if [ $exec_res -ne 0 ]; then
    if [ -s "memo.txt" ]; then
        exit 4
    else
        exit 0
    fi
else
    if [ -s "memo.txt" ]; then
        exit 3
    else
        exit 1
    fi
fi
