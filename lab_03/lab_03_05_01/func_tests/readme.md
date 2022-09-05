# Tests for lab_02 task 5 
## INPUT:
* ##### size_t n - num of lines
* ##### size_t m - num of columns
* ##### int a[i][j] - each element of matrix
## OUTPUT:
* ##### int a - matrix
## POSITIVE TESTS:
1. full 0, 1 <= n <= 10, 1 <= m <= 10, elems w sum of digits > 10 exist
## NEGATIVE TESTS:
1. wrong input, n <= 0
2. worng input, n > 10
3. wrong input, 1 <= n <= 10, elem has wrong type
4. wrong input, 1 <= n <= 10, m < 1
5. worng input, 1 <= n <= 10, m > 10
6. 1 <= n <= 10, 1 <= m <= 10, no elems w sum of digits > 10
