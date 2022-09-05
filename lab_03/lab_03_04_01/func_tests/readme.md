# Tests for lab_03 task 4
## INPUT:
* ##### size_t n - num of lines
* ##### size_t m - num of columns
* ##### int a[i][j] - each element of matrix
## OUTPUT:
* ##### int a - matrix with switched elems
## POSITIVE TESTS:
1. 1 <= n <= 10, 1 <= m <= 10, n = m, even num of columns
2. 1 <= n <= 10, 1 <= m <= 10, n = m, odd num of columns
## NEGATIVE TESTS:
1. wrong input, n <= 0
2. worng input, n > 10
3. wrong input, 1 <= n <= 10, 1 <= m <= 10, elem has wrong type
4. wrong input, 1 <= n <= 10, m <= 0
5. worng input, 1 <= n <= 10, m > 10
6. invalid input, 1 <= n <= 10, 1 <= m <= 10, n != m
