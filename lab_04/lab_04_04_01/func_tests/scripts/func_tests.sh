#!/bin/bash

echo 'FUNC TESTING...';

# Блок проверки позитивных тестов
k=0;
i=0;

exec_res=$?

while true
do
# Получение номера очередного теста
    i=$((i+1));
    if [ $i -le 9 ]; then
        num="0"$i;
    else
        num=$i
    fi

    file_in="../data/pos_$num""_in.txt"; 
    file_out="../data/pos_$num""_out.txt";
    file_args="../data/pos_$num""_args.txt"; 

# Проверка существования и запуск pos_case.sh с передачей в него файлов
    if [ -f $file_out ]; then 
        if [ -f $file_in ]; then 
            if [ -f $file_args ]; then
                ./pos_case.sh $file_in $file_out $file_args;
            else
                ./pos_case.sh $file_in $file_out;
            fi
	fi
    else
        break
    fi
    exec_res=$?
# Информация о результатах очередного теста
    if [ -z "$USE_VALGRIND" ]; then
        if [ $exec_res -eq 0 ]; then echo "POS_$num: PASS";
        else echo "POS_$num: FAILED"; k=$((k+1)); fi
    else
        if [ $exec_res -eq 0 ]; then echo "POS_$num: PASS. Memory: PASS"; fi
        if [ $exec_res -eq 3 ]; then
            echo "POS_$num: FAILED. Memory: FAILED"; k=$((k+1)); fi
        if [ $exec_res -eq 4 ]; then
            echo "POS_$num: PASS. Memory: FAILED"; k=$((k+1)); fi
    fi
done

echo

# Блок проверки негативных тестов
i=0;
while true
do
# Получение номера очередного негативного теста
    i=$((i+1));
    if [ $i -le 9 ]; then
        num="0"$i;
    else
        num=$i
    fi

    file_in="../data/neg_$num""_in.txt";
    file_args="../data/neg_$num""_args.txt";

# Проверка существования и запуск neg_case.sh с передачей ему файлов
    if [ -f $file_in ]; then 
            if [ -f $file_args ]; then
                ./neg_case.sh $file_in $file_args;
            else
                ./neg_case.sh $file_in;
            fi
    else
        break
    fi 
    exec_res=$?
# Информация о прохождении очередного теста
    if [ -z "$USE_VALGRIND" ]; then
        if [ $exec_res -eq 0 ]; then echo "NEG_$num: PASS";
        else echo "NEG_$num: FAILED"; k=$((k+1)); fi
    else
        if [ $exec_res -eq 0 ]; then echo "NEG_$num: PASS. Memory: PASS"; fi
        if [ $exec_res -eq 3 ]; then
            echo "NEG_$num: FAILED. Memory: FAILED"; k=$((k+1)); fi
        if [ $exec_res -eq 4 ]; then
            echo "NEG_$num: PASS. Memory: FAILED"; k=$((k+1)); fi 
    fi	    
done

# Возврат числа непройденных тестов
exit $k;
