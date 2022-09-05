# Tests for lab_03 task 2
## INPUT:
* ##### size_t n - num of lines
* ##### size_t m - num of columns
* ##### int a[i][j] - each element of matrix
## OUTPUT:
* ##### int a - matrix without one row and one column (intersection)
## POSITIVE TESTS:
1. 1 <= n <= 10, 1 <= m <= 10, a[0][0] has min sum of digits
2. 1 <= n <= 10, 1 <= m <= 10, all elems are equal
## NEGATIVE TESTS:
1. wrong input, n <= 0
2. worng input, n > 10
3. wrong input, 1 <= n <= 10, 1 <= m <= 10, elem has wrong type
4. wrong input, 1 <= n <= 10, m <= 0
5. worng input, 1 <= n <= 10, m > 10
