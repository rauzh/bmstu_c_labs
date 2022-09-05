# Tests for lab_03 task 1
## INPUT:
* ##### size_t n - num of lines
* ##### size_t m - num of columns
* ##### int a[i][j] - each element of matrix
## OUTPUT:
* ##### int b - array of zeroes and ones
## POSITIVE TESTS:
1. full 0, 1 <= n <= 10, 1 <= m <= 10, no symmetric rows
2. full 1,  1 <= n <= 10, 1 <= m <= 10, all rows are symmetric
3. 1 0, 1 <= n <= 10, 1 <= m <= 10, first row is symmentric, second is not
## NEGATIVE TESTS:
1. wrong input, n <= 0
2. worng input, n > 10
3. wrong input, 1 <= n <= 10, 1 <= m <= 10, elem has wrong type
4. wrong input, 1 <= n <= 10, m <= 0
5. worng input, 1 <= n <= 10, m > 10
