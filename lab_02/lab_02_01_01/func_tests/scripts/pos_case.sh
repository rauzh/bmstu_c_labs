#!/bin/bash

input=$1;
out_expect=$2;
app="../../app.exe"


# Проверка наличия файла с ключами, его "включение"
if [ $# -eq 3 ]; then
    args="../data/$3"
    app="$app $(cat "$args")"
fi

# Инициализация out.txt
if [ -f out.txt ]; then rm out.txt; fi
touch out.txt

# Инициализация memo.txt
if [ -f memo.txt ]; then rm memo.txt; fi
touch out.txt

# Реализация VALGRIND и запуск без него
if [ -z "$USE_VALGRIND" ]; then
    $app < "$input" > out.txt
else
    valgrind -q --leak-check=full "$app" < "$input" > out.txt 2> memo.txt
fi

exec_res=$?

# Проверка кода завершения app.exe
if [ $exec_res -ne 0 ]; then
    if [ -s "memo.txt" ]; then
        exit 3
    else
        exit 2
    fi	
else 
# Используем компаратор для сравнения ожидаемых и реальных выходных данных
    if ./comparator.sh out.txt "$out_expect"; then
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
fi

