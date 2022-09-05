# Tests for lab_02 task 5 
## INPUT:
* ##### size_t n - длина массива
* ##### int a[i] - каждый элемент массива
## OUTPUT:
* ##### int sum - Сумма ряда, заданного по условию
## POSITIVE TESTS:
1. common test, 1 <= n <= 10, Ряд оканчивается положительным числом
2. check test, 1 <= n <= 10, Ряд оканчивается отрицательным числом, после него есть положительные элементы
## NEGATIVE TESTS:
1. wrong input, n <= 0
2. worng input, n > 10
3. wrong input, 1 <= n <= 10, Элемент задан неправильно (не тот тип данных)
4. no prime elems
