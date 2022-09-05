/*
	ТРЕТЬЕ ЗАДАНИЕ

используемый тип чисел: int
общий моментик:

"./app.exe c 120 out.txt"
	- Создание бинарного файла out.txt,
		в который помещается 120 случайных чисел

"./app.exe p out.txt"
	- Прочтение из бин айла out.txt чисел и их вывод на экран

"./app.exe s out.txt"
	- Сортировка выбором чисел в бин файле out.txt по возрастанию

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "types.h"
#include "funcs_sort.h"
#include "funcs_io.h"
#include "main_branches.h"

int main(int argc, const char *const argv[])
{
    if ((argc != 3) && (argc != 4))
        return INVALID_ARGS_AMOUNT;

    int rc = EXIT_SUCCESS;

    if ((strcmp(argv[1], "c") == EQUAL) && (argc == 4))
        rc = bin_file_filling_task(argv);
    else if ((strcmp(argv[1], "p") == EQUAL) && (argc == 3))
        rc = bin_file_printing_task(argv);
    else if ((strcmp(argv[1], "s") == EQUAL) && (argc == 3))
        rc = bin_file_sorting_task(argv);
    else
        return INVALID_ARGS;

    return rc;
}
