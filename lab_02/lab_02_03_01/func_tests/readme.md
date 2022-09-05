# Tests for lab_02 task 2 
## INPUT:
* ##### size_t n - length of array
* ##### int a[i] - each element of array
## OUTPUT:
* ##### int b - array of prime elemets of a
## POSITIVE TESTS:
1. common test, 1 <= n <= 10, % 3 == 0 elems exist 
2. common test, n = 1, elem % 3 ==0
3. check test, 1 <= n <= 10, no elems % 3 == 0
4. common test, n = 10, all elems % 3 == 0
## NEGATIVE TESTS:
1. wrong input, n <= 0
2. worng input, n > 10
3. wrong input, 1 <= n <= 10, elem has wrong type

